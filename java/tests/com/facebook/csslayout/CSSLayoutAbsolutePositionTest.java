/**
 * Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

 // @Generated by gentest/gentest.rb from gentest/fixtures/CSSLayoutAbsolutePositionTest.html

package com.facebook.csslayout;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class CSSLayoutAbsolutePositionTest {
  @Test
  public void test_absolute_layout_width_height_start_top() {
    final CSSNode root = new CSSNode();
    root.setWidth(100f);
    root.setHeight(100f);

    final CSSNode root_child0 = new CSSNode();
    root_child0.setPositionType(YogaPositionType.ABSOLUTE);
    root_child0.setPosition(YogaEdge.START, 10f);
    root_child0.setPosition(YogaEdge.TOP, 10f);
    root_child0.setWidth(10f);
    root_child0.setHeight(10f);
    root.addChildAt(root_child0, 0);
    root.setDirection(YogaDirection.LTR);
    root.calculateLayout();

    assertEquals(0f, root.getLayoutX(), 0.0f);
    assertEquals(0f, root.getLayoutY(), 0.0f);
    assertEquals(100f, root.getLayoutWidth(), 0.0f);
    assertEquals(100f, root.getLayoutHeight(), 0.0f);

    assertEquals(10f, root_child0.getLayoutX(), 0.0f);
    assertEquals(10f, root_child0.getLayoutY(), 0.0f);
    assertEquals(10f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(10f, root_child0.getLayoutHeight(), 0.0f);

    root.setDirection(YogaDirection.RTL);
    root.calculateLayout();

    assertEquals(0f, root.getLayoutX(), 0.0f);
    assertEquals(0f, root.getLayoutY(), 0.0f);
    assertEquals(100f, root.getLayoutWidth(), 0.0f);
    assertEquals(100f, root.getLayoutHeight(), 0.0f);

    assertEquals(80f, root_child0.getLayoutX(), 0.0f);
    assertEquals(10f, root_child0.getLayoutY(), 0.0f);
    assertEquals(10f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(10f, root_child0.getLayoutHeight(), 0.0f);
  }

  @Test
  public void test_absolute_layout_width_height_end_bottom() {
    final CSSNode root = new CSSNode();
    root.setWidth(100f);
    root.setHeight(100f);

    final CSSNode root_child0 = new CSSNode();
    root_child0.setPositionType(YogaPositionType.ABSOLUTE);
    root_child0.setPosition(YogaEdge.END, 10f);
    root_child0.setPosition(YogaEdge.BOTTOM, 10f);
    root_child0.setWidth(10f);
    root_child0.setHeight(10f);
    root.addChildAt(root_child0, 0);
    root.setDirection(YogaDirection.LTR);
    root.calculateLayout();

    assertEquals(0f, root.getLayoutX(), 0.0f);
    assertEquals(0f, root.getLayoutY(), 0.0f);
    assertEquals(100f, root.getLayoutWidth(), 0.0f);
    assertEquals(100f, root.getLayoutHeight(), 0.0f);

    assertEquals(80f, root_child0.getLayoutX(), 0.0f);
    assertEquals(80f, root_child0.getLayoutY(), 0.0f);
    assertEquals(10f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(10f, root_child0.getLayoutHeight(), 0.0f);

    root.setDirection(YogaDirection.RTL);
    root.calculateLayout();

    assertEquals(0f, root.getLayoutX(), 0.0f);
    assertEquals(0f, root.getLayoutY(), 0.0f);
    assertEquals(100f, root.getLayoutWidth(), 0.0f);
    assertEquals(100f, root.getLayoutHeight(), 0.0f);

    assertEquals(10f, root_child0.getLayoutX(), 0.0f);
    assertEquals(80f, root_child0.getLayoutY(), 0.0f);
    assertEquals(10f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(10f, root_child0.getLayoutHeight(), 0.0f);
  }

  @Test
  public void test_absolute_layout_start_top_end_bottom() {
    final CSSNode root = new CSSNode();
    root.setWidth(100f);
    root.setHeight(100f);

    final CSSNode root_child0 = new CSSNode();
    root_child0.setPositionType(YogaPositionType.ABSOLUTE);
    root_child0.setPosition(YogaEdge.START, 10f);
    root_child0.setPosition(YogaEdge.TOP, 10f);
    root_child0.setPosition(YogaEdge.END, 10f);
    root_child0.setPosition(YogaEdge.BOTTOM, 10f);
    root.addChildAt(root_child0, 0);
    root.setDirection(YogaDirection.LTR);
    root.calculateLayout();

    assertEquals(0f, root.getLayoutX(), 0.0f);
    assertEquals(0f, root.getLayoutY(), 0.0f);
    assertEquals(100f, root.getLayoutWidth(), 0.0f);
    assertEquals(100f, root.getLayoutHeight(), 0.0f);

    assertEquals(10f, root_child0.getLayoutX(), 0.0f);
    assertEquals(10f, root_child0.getLayoutY(), 0.0f);
    assertEquals(80f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(80f, root_child0.getLayoutHeight(), 0.0f);

    root.setDirection(YogaDirection.RTL);
    root.calculateLayout();

    assertEquals(0f, root.getLayoutX(), 0.0f);
    assertEquals(0f, root.getLayoutY(), 0.0f);
    assertEquals(100f, root.getLayoutWidth(), 0.0f);
    assertEquals(100f, root.getLayoutHeight(), 0.0f);

    assertEquals(10f, root_child0.getLayoutX(), 0.0f);
    assertEquals(10f, root_child0.getLayoutY(), 0.0f);
    assertEquals(80f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(80f, root_child0.getLayoutHeight(), 0.0f);
  }

  @Test
  public void test_absolute_layout_width_height_start_top_end_bottom() {
    final CSSNode root = new CSSNode();
    root.setWidth(100f);
    root.setHeight(100f);

    final CSSNode root_child0 = new CSSNode();
    root_child0.setPositionType(YogaPositionType.ABSOLUTE);
    root_child0.setPosition(YogaEdge.START, 10f);
    root_child0.setPosition(YogaEdge.TOP, 10f);
    root_child0.setPosition(YogaEdge.END, 10f);
    root_child0.setPosition(YogaEdge.BOTTOM, 10f);
    root_child0.setWidth(10f);
    root_child0.setHeight(10f);
    root.addChildAt(root_child0, 0);
    root.setDirection(YogaDirection.LTR);
    root.calculateLayout();

    assertEquals(0f, root.getLayoutX(), 0.0f);
    assertEquals(0f, root.getLayoutY(), 0.0f);
    assertEquals(100f, root.getLayoutWidth(), 0.0f);
    assertEquals(100f, root.getLayoutHeight(), 0.0f);

    assertEquals(10f, root_child0.getLayoutX(), 0.0f);
    assertEquals(10f, root_child0.getLayoutY(), 0.0f);
    assertEquals(10f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(10f, root_child0.getLayoutHeight(), 0.0f);

    root.setDirection(YogaDirection.RTL);
    root.calculateLayout();

    assertEquals(0f, root.getLayoutX(), 0.0f);
    assertEquals(0f, root.getLayoutY(), 0.0f);
    assertEquals(100f, root.getLayoutWidth(), 0.0f);
    assertEquals(100f, root.getLayoutHeight(), 0.0f);

    assertEquals(80f, root_child0.getLayoutX(), 0.0f);
    assertEquals(10f, root_child0.getLayoutY(), 0.0f);
    assertEquals(10f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(10f, root_child0.getLayoutHeight(), 0.0f);
  }

  @Test
  public void test_do_not_clamp_height_of_absolute_node_to_height_of_its_overflow_hidden_parent() {
    final CSSNode root = new CSSNode();
    root.setFlexDirection(YogaFlexDirection.ROW);
    root.setOverflow(YogaOverflow.HIDDEN);
    root.setWidth(50f);
    root.setHeight(50f);

    final CSSNode root_child0 = new CSSNode();
    root_child0.setPositionType(YogaPositionType.ABSOLUTE);
    root_child0.setPosition(YogaEdge.START, 0f);
    root_child0.setPosition(YogaEdge.TOP, 0f);
    root.addChildAt(root_child0, 0);

    final CSSNode root_child0_child0 = new CSSNode();
    root_child0_child0.setWidth(100f);
    root_child0_child0.setHeight(100f);
    root_child0.addChildAt(root_child0_child0, 0);
    root.setDirection(YogaDirection.LTR);
    root.calculateLayout();

    assertEquals(0f, root.getLayoutX(), 0.0f);
    assertEquals(0f, root.getLayoutY(), 0.0f);
    assertEquals(50f, root.getLayoutWidth(), 0.0f);
    assertEquals(50f, root.getLayoutHeight(), 0.0f);

    assertEquals(0f, root_child0.getLayoutX(), 0.0f);
    assertEquals(0f, root_child0.getLayoutY(), 0.0f);
    assertEquals(100f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(100f, root_child0.getLayoutHeight(), 0.0f);

    assertEquals(0f, root_child0_child0.getLayoutX(), 0.0f);
    assertEquals(0f, root_child0_child0.getLayoutY(), 0.0f);
    assertEquals(100f, root_child0_child0.getLayoutWidth(), 0.0f);
    assertEquals(100f, root_child0_child0.getLayoutHeight(), 0.0f);

    root.setDirection(YogaDirection.RTL);
    root.calculateLayout();

    assertEquals(0f, root.getLayoutX(), 0.0f);
    assertEquals(0f, root.getLayoutY(), 0.0f);
    assertEquals(50f, root.getLayoutWidth(), 0.0f);
    assertEquals(50f, root.getLayoutHeight(), 0.0f);

    assertEquals(-50f, root_child0.getLayoutX(), 0.0f);
    assertEquals(0f, root_child0.getLayoutY(), 0.0f);
    assertEquals(100f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(100f, root_child0.getLayoutHeight(), 0.0f);

    assertEquals(0f, root_child0_child0.getLayoutX(), 0.0f);
    assertEquals(0f, root_child0_child0.getLayoutY(), 0.0f);
    assertEquals(100f, root_child0_child0.getLayoutWidth(), 0.0f);
    assertEquals(100f, root_child0_child0.getLayoutHeight(), 0.0f);
  }

  @Test
  public void test_absolute_layout_within_border() {
    final CSSNode root = new CSSNode();
    root.setMargin(YogaEdge.LEFT, 10f);
    root.setMargin(YogaEdge.TOP, 10f);
    root.setMargin(YogaEdge.RIGHT, 10f);
    root.setMargin(YogaEdge.BOTTOM, 10f);
    root.setPadding(YogaEdge.LEFT, 10);
    root.setPadding(YogaEdge.TOP, 10);
    root.setPadding(YogaEdge.RIGHT, 10);
    root.setPadding(YogaEdge.BOTTOM, 10);
    root.setBorder(YogaEdge.LEFT, 10f);
    root.setBorder(YogaEdge.TOP, 10f);
    root.setBorder(YogaEdge.RIGHT, 10f);
    root.setBorder(YogaEdge.BOTTOM, 10f);
    root.setWidth(100f);
    root.setHeight(100f);

    final CSSNode root_child0 = new CSSNode();
    root_child0.setPositionType(YogaPositionType.ABSOLUTE);
    root_child0.setPosition(YogaEdge.LEFT, 0f);
    root_child0.setPosition(YogaEdge.TOP, 0f);
    root_child0.setWidth(50f);
    root_child0.setHeight(50f);
    root.addChildAt(root_child0, 0);

    final CSSNode root_child1 = new CSSNode();
    root_child1.setPositionType(YogaPositionType.ABSOLUTE);
    root_child1.setPosition(YogaEdge.RIGHT, 0f);
    root_child1.setPosition(YogaEdge.BOTTOM, 0f);
    root_child1.setWidth(50f);
    root_child1.setHeight(50f);
    root.addChildAt(root_child1, 1);
    root.setDirection(YogaDirection.LTR);
    root.calculateLayout();

    assertEquals(10f, root.getLayoutX(), 0.0f);
    assertEquals(10f, root.getLayoutY(), 0.0f);
    assertEquals(100f, root.getLayoutWidth(), 0.0f);
    assertEquals(100f, root.getLayoutHeight(), 0.0f);

    assertEquals(10f, root_child0.getLayoutX(), 0.0f);
    assertEquals(10f, root_child0.getLayoutY(), 0.0f);
    assertEquals(50f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(50f, root_child0.getLayoutHeight(), 0.0f);

    assertEquals(40f, root_child1.getLayoutX(), 0.0f);
    assertEquals(40f, root_child1.getLayoutY(), 0.0f);
    assertEquals(50f, root_child1.getLayoutWidth(), 0.0f);
    assertEquals(50f, root_child1.getLayoutHeight(), 0.0f);

    root.setDirection(YogaDirection.RTL);
    root.calculateLayout();

    assertEquals(10f, root.getLayoutX(), 0.0f);
    assertEquals(10f, root.getLayoutY(), 0.0f);
    assertEquals(100f, root.getLayoutWidth(), 0.0f);
    assertEquals(100f, root.getLayoutHeight(), 0.0f);

    assertEquals(10f, root_child0.getLayoutX(), 0.0f);
    assertEquals(10f, root_child0.getLayoutY(), 0.0f);
    assertEquals(50f, root_child0.getLayoutWidth(), 0.0f);
    assertEquals(50f, root_child0.getLayoutHeight(), 0.0f);

    assertEquals(40f, root_child1.getLayoutX(), 0.0f);
    assertEquals(40f, root_child1.getLayoutY(), 0.0f);
    assertEquals(50f, root_child1.getLayoutWidth(), 0.0f);
    assertEquals(50f, root_child1.getLayoutHeight(), 0.0f);
  }

}
