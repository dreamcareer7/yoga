
#include "Layout-test-utils.h"
#include <stdlib.h>

static bool eq(float a, float b) {
  return fabs(a - b) < 0.0001;
}

static bool are_layout_equal(css_node_t *a, css_node_t *b) {
  if (!eq(a->layout.dimensions[CSS_WIDTH], b->layout.dimensions[CSS_WIDTH]) ||
      !eq(a->layout.dimensions[CSS_HEIGHT], b->layout.dimensions[CSS_HEIGHT]) ||
      !eq(a->layout.position[CSS_TOP], b->layout.position[CSS_TOP]) ||
      !eq(a->layout.position[CSS_LEFT], b->layout.position[CSS_LEFT]) ||
      !eq(a->children_count, b->children_count)) {
    return false;
  }
  for (int i = 0; i < a->children_count; ++i) {
    if (!are_layout_equal(a->get_child(a->context, i), b->get_child(b->context, i))) {
      return false;
    }
  }
  return true;
}

css_dim_t measure(void *context, float width) {
  const char *text = context;
  css_dim_t dim;
  if (width != width) {
    width = 1000000;
  }
  if (strcmp(text, "small") == 0) {
    dim.dimensions[CSS_WIDTH] = fminf(33, width);
    dim.dimensions[CSS_HEIGHT] = 18;
    return dim;
  }
  if (strcmp(text, "loooooooooong with space") == 0) {
    dim.dimensions[CSS_WIDTH] = width >= 171 ? 171 : fmaxf(100, width);
    dim.dimensions[CSS_HEIGHT] = width >= 171 ? 18 : 36;
    return dim;
  }

  // Should not go here
  dim.dimensions[CSS_WIDTH] = CSS_UNDEFINED;
  dim.dimensions[CSS_HEIGHT] = CSS_UNDEFINED;
  return dim;
}

void test(const char *name, css_node_t *style, css_node_t *expected_layout) {
  layoutNode(style, CSS_UNDEFINED);

  if (!are_layout_equal(style, expected_layout)) {
    printf("%sFAIL%s %s\n", "\x1B[31m", "\x1B[0m", name);

    printf("Input:    ");
    print_css_node(style, CSS_PRINT_STYLE);
    printf("Output:   ");
    print_css_node(style, CSS_PRINT_LAYOUT);

    printf("Expected: ");
    print_css_node(expected_layout, CSS_PRINT_LAYOUT);
  } else {
    printf("%sPASS%s %s\n", "\x1B[32m", "\x1B[0m",  name);
  }

  free_css_node(style);
  free_css_node(expected_layout);
}

static css_node_t* get_child(void *context, int i) {
  css_node_t* children = (css_node_t*)context;
  return &children[i];
}

static bool is_dirty(void *context) {
  (void)context; // remove unused warning
  return true;
}

static void init_test_css_node(css_node_t *node) {
  node->get_child = get_child;
  node->is_dirty = is_dirty;
}

css_node_t *new_test_css_node(void) {
  css_node_t *node = new_css_node();
  init_test_css_node(node);
  return node;
}

void init_css_node_children(css_node_t *node, int children_count) {
  node->context = calloc((size_t)children_count, sizeof(css_node_t));
  for (int i = 0; i < children_count; ++i) {
    init_css_node(node->get_child(node->context, i));
    init_test_css_node(node->get_child(node->context, i));
  }
  node->children_count = children_count;
}
