/**
 * Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

 // @Generated by gentest/gentest.rb from gentest/fixtures/CSSLayoutPaddingTest.html

#include <CSSLayout/CSSLayout.h>
#include <gtest/gtest.h>

TEST(CSSLayoutTest, padding_no_size) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetPadding(root, YGEdgeLeft, 10);
  CSSNodeStyleSetPadding(root, YGEdgeTop, 10);
  CSSNodeStyleSetPadding(root, YGEdgeRight, 10);
  CSSNodeStyleSetPadding(root, YGEdgeBottom, 10);
  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetHeight(root));

  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetHeight(root));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, padding_container_match_child) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetPadding(root, YGEdgeLeft, 10);
  CSSNodeStyleSetPadding(root, YGEdgeTop, 10);
  CSSNodeStyleSetPadding(root, YGEdgeRight, 10);
  CSSNodeStyleSetPadding(root, YGEdgeBottom, 10);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child0, 10);
  CSSNodeStyleSetHeight(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);
  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(30, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(30, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(30, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(30, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, padding_flex_child) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetPadding(root, YGEdgeLeft, 10);
  CSSNodeStyleSetPadding(root, YGEdgeTop, 10);
  CSSNodeStyleSetPadding(root, YGEdgeRight, 10);
  CSSNodeStyleSetPadding(root, YGEdgeBottom, 10);
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetFlexGrow(root_child0, 1);
  CSSNodeStyleSetWidth(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);
  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(80, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, padding_stretch_child) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetPadding(root, YGEdgeLeft, 10);
  CSSNodeStyleSetPadding(root, YGEdgeTop, 10);
  CSSNodeStyleSetPadding(root, YGEdgeRight, 10);
  CSSNodeStyleSetPadding(root, YGEdgeBottom, 10);
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetHeight(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);
  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(80, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(80, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, padding_center_child) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetJustifyContent(root, YGJustifyCenter);
  CSSNodeStyleSetAlignItems(root, YGAlignCenter);
  CSSNodeStyleSetPadding(root, YGEdgeStart, 10);
  CSSNodeStyleSetPadding(root, YGEdgeEnd, 20);
  CSSNodeStyleSetPadding(root, YGEdgeBottom, 20);
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child0, 10);
  CSSNodeStyleSetHeight(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);
  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(40, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(35, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(50, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(35, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, child_with_padding_align_end) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetJustifyContent(root, YGJustifyFlexEnd);
  CSSNodeStyleSetAlignItems(root, YGAlignFlexEnd);
  CSSNodeStyleSetWidth(root, 200);
  CSSNodeStyleSetHeight(root, 200);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetPadding(root_child0, YGEdgeLeft, 20);
  CSSNodeStyleSetPadding(root_child0, YGEdgeTop, 20);
  CSSNodeStyleSetPadding(root_child0, YGEdgeRight, 20);
  CSSNodeStyleSetPadding(root_child0, YGEdgeBottom, 20);
  CSSNodeStyleSetWidth(root_child0, 100);
  CSSNodeStyleSetHeight(root_child0, 100);
  CSSNodeInsertChild(root, root_child0, 0);
  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeFreeRecursive(root);
}
