/**
 * Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

/**
 * @Generated by gentest/gentest.sh with the following input
 *
<div id="flex_direction_column_no_height" style="width: 100px">
  <div style="height: 10px;"></div>
  <div style="height: 10px;"></div>
  <div style="height: 10px;"></div>
</div>

<div id="flex_direction_row_no_width" style="height: 100px; flex-direction: row;">
  <div style="width: 10px;"></div>
  <div style="width: 10px;"></div>
  <div style="width: 10px;"></div>
</div>

<div id="flex_direction_column" style="height: 100px; width: 100px;">
  <div style="height: 10px;"></div>
  <div style="height: 10px;"></div>
  <div style="height: 10px;"></div>
</div>

<div id="flex_direction_row" style="height: 100px; width: 100px; flex-direction: row;">
  <div style="width: 10px;"></div>
  <div style="width: 10px;"></div>
  <div style="width: 10px;"></div>
</div>

<div id="flex_direction_column_reverse" style="height: 100px; width: 100px; flex-direction: column-reverse;">
  <div style="height: 10px;"></div>
  <div style="height: 10px;"></div>
  <div style="height: 10px;"></div>
</div>

<div id="flex_direction_row_reverse" style="height: 100px; width: 100px; flex-direction: row-reverse;">
  <div style="width: 10px;"></div>
  <div style="width: 10px;"></div>
  <div style="width: 10px;"></div>
</div>
 *
 */

#include <CSSLayout/CSSLayout.h>
#include <gtest/gtest.h>

TEST(CSSLayoutTest, flex_direction_column_no_height) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetWidth(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetHeight(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child1 = CSSNodeNew();
  CSSNodeStyleSetHeight(root_child1, 10);
  CSSNodeInsertChild(root, root_child1, 1);

  const CSSNodeRef root_child2 = CSSNodeNew();
  CSSNodeStyleSetHeight(root_child2, 10);
  CSSNodeInsertChild(root, root_child2, 2);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(30, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(30, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, flex_direction_row_no_width) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetFlexDirection(root, CSSFlexDirectionRow);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child1 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child1, 10);
  CSSNodeInsertChild(root, root_child1, 1);

  const CSSNodeRef root_child2 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child2, 10);
  CSSNodeInsertChild(root, root_child2, 2);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(30, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(30, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, flex_direction_column) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetHeight(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child1 = CSSNodeNew();
  CSSNodeStyleSetHeight(root_child1, 10);
  CSSNodeInsertChild(root, root_child1, 1);

  const CSSNodeRef root_child2 = CSSNodeNew();
  CSSNodeStyleSetHeight(root_child2, 10);
  CSSNodeInsertChild(root, root_child2, 2);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, flex_direction_row) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetFlexDirection(root, CSSFlexDirectionRow);
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child1 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child1, 10);
  CSSNodeInsertChild(root, root_child1, 1);

  const CSSNodeRef root_child2 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child2, 10);
  CSSNodeInsertChild(root, root_child2, 2);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(90, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(80, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(70, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, flex_direction_column_reverse) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetFlexDirection(root, CSSFlexDirectionColumnReverse);
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetHeight(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child1 = CSSNodeNew();
  CSSNodeStyleSetHeight(root_child1, 10);
  CSSNodeInsertChild(root, root_child1, 1);

  const CSSNodeRef root_child2 = CSSNodeNew();
  CSSNodeStyleSetHeight(root_child2, 10);
  CSSNodeInsertChild(root, root_child2, 2);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(90, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(80, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(70, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(90, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(80, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(70, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, flex_direction_row_reverse) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetFlexDirection(root, CSSFlexDirectionRowReverse);
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child1 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child1, 10);
  CSSNodeInsertChild(root, root_child1, 1);

  const CSSNodeRef root_child2 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child2, 10);
  CSSNodeInsertChild(root, root_child2, 2);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(90, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(80, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(70, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(20, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, CSSNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(10, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeFreeRecursive(root);
}
