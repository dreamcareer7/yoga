/**
 * Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

// @Generated by gentest/gentest.rb from gentest/fixtures/YGJustifyContentTest.html

#include <gtest/gtest.h>
#include <yoga/Yoga.h>

TEST(YogaTest, justify_content_row_flex_start) {
  const YGNodeRef root = YGNodeNew();
  YGNodeStyleSetFlexDirection(root, YGFlexDirectionRow);
  YGNodeStyleSetWidth(root, 102);
  YGNodeStyleSetHeight(root, 102);

  const YGNodeRef root_child0 = YGNodeNew();
  YGNodeStyleSetWidth(root_child0, 10);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNew();
  YGNodeStyleSetWidth(root_child1, 10);
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child2 = YGNodeNew();
  YGNodeStyleSetWidth(root_child2, 10);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(20, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(92, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(82, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(72, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);
}

TEST(YogaTest, justify_content_row_flex_end) {
  const YGNodeRef root = YGNodeNew();
  YGNodeStyleSetFlexDirection(root, YGFlexDirectionRow);
  YGNodeStyleSetJustifyContent(root, YGJustifyFlexEnd);
  YGNodeStyleSetWidth(root, 102);
  YGNodeStyleSetHeight(root, 102);

  const YGNodeRef root_child0 = YGNodeNew();
  YGNodeStyleSetWidth(root_child0, 10);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNew();
  YGNodeStyleSetWidth(root_child1, 10);
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child2 = YGNodeNew();
  YGNodeStyleSetWidth(root_child2, 10);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(72, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(82, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(92, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(20, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);
}

TEST(YogaTest, justify_content_row_center) {
  const YGNodeRef root = YGNodeNew();
  YGNodeStyleSetFlexDirection(root, YGFlexDirectionRow);
  YGNodeStyleSetJustifyContent(root, YGJustifyCenter);
  YGNodeStyleSetWidth(root, 102);
  YGNodeStyleSetHeight(root, 102);

  const YGNodeRef root_child0 = YGNodeNew();
  YGNodeStyleSetWidth(root_child0, 10);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNew();
  YGNodeStyleSetWidth(root_child1, 10);
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child2 = YGNodeNew();
  YGNodeStyleSetWidth(root_child2, 10);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(36, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(56, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(56, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(36, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);
}

TEST(YogaTest, justify_content_row_space_between) {
  const YGNodeRef root = YGNodeNew();
  YGNodeStyleSetFlexDirection(root, YGFlexDirectionRow);
  YGNodeStyleSetJustifyContent(root, YGJustifySpaceBetween);
  YGNodeStyleSetWidth(root, 102);
  YGNodeStyleSetHeight(root, 102);

  const YGNodeRef root_child0 = YGNodeNew();
  YGNodeStyleSetWidth(root_child0, 10);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNew();
  YGNodeStyleSetWidth(root_child1, 10);
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child2 = YGNodeNew();
  YGNodeStyleSetWidth(root_child2, 10);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(92, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(92, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);
}

TEST(YogaTest, justify_content_row_space_around) {
  const YGNodeRef root = YGNodeNew();
  YGNodeStyleSetFlexDirection(root, YGFlexDirectionRow);
  YGNodeStyleSetJustifyContent(root, YGJustifySpaceAround);
  YGNodeStyleSetWidth(root, 102);
  YGNodeStyleSetHeight(root, 102);

  const YGNodeRef root_child0 = YGNodeNew();
  YGNodeStyleSetWidth(root_child0, 10);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNew();
  YGNodeStyleSetWidth(root_child1, 10);
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child2 = YGNodeNew();
  YGNodeStyleSetWidth(root_child2, 10);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(12, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(12, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);
}

TEST(YogaTest, justify_content_column_flex_start) {
  const YGNodeRef root = YGNodeNew();
  YGNodeStyleSetWidth(root, 102);
  YGNodeStyleSetHeight(root, 102);

  const YGNodeRef root_child0 = YGNodeNew();
  YGNodeStyleSetHeight(root_child0, 10);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNew();
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child2 = YGNodeNew();
  YGNodeStyleSetHeight(root_child2, 10);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);
}

TEST(YogaTest, justify_content_column_flex_end) {
  const YGNodeRef root = YGNodeNew();
  YGNodeStyleSetJustifyContent(root, YGJustifyFlexEnd);
  YGNodeStyleSetWidth(root, 102);
  YGNodeStyleSetHeight(root, 102);

  const YGNodeRef root_child0 = YGNodeNew();
  YGNodeStyleSetHeight(root_child0, 10);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNew();
  YGNodeStyleSetHeight(root_child1, 10);
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child2 = YGNodeNew();
  YGNodeStyleSetHeight(root_child2, 10);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(72, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(82, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(92, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(72, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(82, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(92, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);
}

TEST(YogaTest, justify_content_column_center) {
  const YGNodeRef root = YGNodeNew();
  YGNodeStyleSetJustifyContent(root, YGJustifyCenter);
  YGNodeStyleSetWidth(root, 102);
  YGNodeStyleSetHeight(root, 102);

  const YGNodeRef root_child0 = YGNodeNew();
  YGNodeStyleSetHeight(root_child0, 10);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNew();
  YGNodeStyleSetHeight(root_child1, 10);
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child2 = YGNodeNew();
  YGNodeStyleSetHeight(root_child2, 10);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(36, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(56, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(36, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(56, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);
}

TEST(YogaTest, justify_content_column_space_between) {
  const YGNodeRef root = YGNodeNew();
  YGNodeStyleSetJustifyContent(root, YGJustifySpaceBetween);
  YGNodeStyleSetWidth(root, 102);
  YGNodeStyleSetHeight(root, 102);

  const YGNodeRef root_child0 = YGNodeNew();
  YGNodeStyleSetHeight(root_child0, 10);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNew();
  YGNodeStyleSetHeight(root_child1, 10);
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child2 = YGNodeNew();
  YGNodeStyleSetHeight(root_child2, 10);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(92, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(92, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);
}

TEST(YogaTest, justify_content_column_space_around) {
  const YGNodeRef root = YGNodeNew();
  YGNodeStyleSetJustifyContent(root, YGJustifySpaceAround);
  YGNodeStyleSetWidth(root, 102);
  YGNodeStyleSetHeight(root, 102);

  const YGNodeRef root_child0 = YGNodeNew();
  YGNodeStyleSetHeight(root_child0, 10);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNew();
  YGNodeStyleSetHeight(root_child1, 10);
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child2 = YGNodeNew();
  YGNodeStyleSetHeight(root_child2, 10);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(12, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(12, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(46, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(102, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);
}
