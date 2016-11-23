/**
 * Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

 // @Generated by gentest/gentest.rb from gentest/fixtures/CSSLayoutFlexTest.html

using System;
using NUnit.Framework;

namespace Facebook.CSSLayout
{
    [TestFixture]
    public class CSSLayoutFlexTest
    {
        [Test]
        public void Test_flex_basis_flex_grow_column()
        {
            CSSNode root = new CSSNode();
            root.StyleWidth = 100f;
            root.StyleHeight = 100f;

            CSSNode root_child0 = new CSSNode();
            root_child0.FlexGrow = 1f;
            root_child0.FlexBasis = 50f;
            root.Insert(0, root_child0);

            CSSNode root_child1 = new CSSNode();
            root_child1.FlexGrow = 1f;
            root.Insert(1, root_child1);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(100f, root_child0.LayoutWidth);
            Assert.AreEqual(75f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(75f, root_child1.LayoutY);
            Assert.AreEqual(100f, root_child1.LayoutWidth);
            Assert.AreEqual(25f, root_child1.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(100f, root_child0.LayoutWidth);
            Assert.AreEqual(75f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(75f, root_child1.LayoutY);
            Assert.AreEqual(100f, root_child1.LayoutWidth);
            Assert.AreEqual(25f, root_child1.LayoutHeight);
        }

        [Test]
        public void Test_flex_basis_flex_grow_row()
        {
            CSSNode root = new CSSNode();
            root.FlexDirection = CSSFlexDirection.Row;
            root.StyleWidth = 100f;
            root.StyleHeight = 100f;

            CSSNode root_child0 = new CSSNode();
            root_child0.FlexGrow = 1f;
            root_child0.FlexBasis = 50f;
            root.Insert(0, root_child0);

            CSSNode root_child1 = new CSSNode();
            root_child1.FlexGrow = 1f;
            root.Insert(1, root_child1);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(75f, root_child0.LayoutWidth);
            Assert.AreEqual(100f, root_child0.LayoutHeight);

            Assert.AreEqual(75f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(25f, root_child1.LayoutWidth);
            Assert.AreEqual(100f, root_child1.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(25f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(75f, root_child0.LayoutWidth);
            Assert.AreEqual(100f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(25f, root_child1.LayoutWidth);
            Assert.AreEqual(100f, root_child1.LayoutHeight);
        }

        [Test]
        public void Test_flex_basis_flex_shrink_column()
        {
            CSSNode root = new CSSNode();
            root.StyleWidth = 100f;
            root.StyleHeight = 100f;

            CSSNode root_child0 = new CSSNode();
            root_child0.FlexShrink = 1f;
            root_child0.FlexBasis = 100f;
            root.Insert(0, root_child0);

            CSSNode root_child1 = new CSSNode();
            root_child1.FlexBasis = 50f;
            root.Insert(1, root_child1);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(100f, root_child0.LayoutWidth);
            Assert.AreEqual(50f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(50f, root_child1.LayoutY);
            Assert.AreEqual(100f, root_child1.LayoutWidth);
            Assert.AreEqual(50f, root_child1.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(100f, root_child0.LayoutWidth);
            Assert.AreEqual(50f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(50f, root_child1.LayoutY);
            Assert.AreEqual(100f, root_child1.LayoutWidth);
            Assert.AreEqual(50f, root_child1.LayoutHeight);
        }

        [Test]
        public void Test_flex_basis_flex_shrink_row()
        {
            CSSNode root = new CSSNode();
            root.FlexDirection = CSSFlexDirection.Row;
            root.StyleWidth = 100f;
            root.StyleHeight = 100f;

            CSSNode root_child0 = new CSSNode();
            root_child0.FlexShrink = 1f;
            root_child0.FlexBasis = 100f;
            root.Insert(0, root_child0);

            CSSNode root_child1 = new CSSNode();
            root_child1.FlexBasis = 50f;
            root.Insert(1, root_child1);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(50f, root_child0.LayoutWidth);
            Assert.AreEqual(100f, root_child0.LayoutHeight);

            Assert.AreEqual(50f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(50f, root_child1.LayoutWidth);
            Assert.AreEqual(100f, root_child1.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(50f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(50f, root_child0.LayoutWidth);
            Assert.AreEqual(100f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(50f, root_child1.LayoutWidth);
            Assert.AreEqual(100f, root_child1.LayoutHeight);
        }

        [Test]
        public void Test_flex_shrink_to_zero()
        {
            CSSNode root = new CSSNode();
            root.StyleHeight = 75f;

            CSSNode root_child0 = new CSSNode();
            root_child0.StyleWidth = 50f;
            root_child0.StyleHeight = 50f;
            root.Insert(0, root_child0);

            CSSNode root_child1 = new CSSNode();
            root_child1.FlexShrink = 1f;
            root_child1.StyleWidth = 50f;
            root_child1.StyleHeight = 50f;
            root.Insert(1, root_child1);

            CSSNode root_child2 = new CSSNode();
            root_child2.StyleWidth = 50f;
            root_child2.StyleHeight = 50f;
            root.Insert(2, root_child2);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(50f, root.LayoutWidth);
            Assert.AreEqual(75f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(50f, root_child0.LayoutWidth);
            Assert.AreEqual(50f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(50f, root_child1.LayoutY);
            Assert.AreEqual(50f, root_child1.LayoutWidth);
            Assert.AreEqual(0f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(50f, root_child2.LayoutY);
            Assert.AreEqual(50f, root_child2.LayoutWidth);
            Assert.AreEqual(50f, root_child2.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(50f, root.LayoutWidth);
            Assert.AreEqual(75f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(50f, root_child0.LayoutWidth);
            Assert.AreEqual(50f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(50f, root_child1.LayoutY);
            Assert.AreEqual(50f, root_child1.LayoutWidth);
            Assert.AreEqual(0f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(50f, root_child2.LayoutY);
            Assert.AreEqual(50f, root_child2.LayoutWidth);
            Assert.AreEqual(50f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_flex_basis_overrides_main_size()
        {
            CSSNode root = new CSSNode();
            root.StyleWidth = 100f;
            root.StyleHeight = 100f;

            CSSNode root_child0 = new CSSNode();
            root_child0.FlexGrow = 1f;
            root_child0.FlexBasis = 50f;
            root_child0.StyleHeight = 20f;
            root.Insert(0, root_child0);

            CSSNode root_child1 = new CSSNode();
            root_child1.FlexGrow = 1f;
            root_child1.StyleHeight = 10f;
            root.Insert(1, root_child1);

            CSSNode root_child2 = new CSSNode();
            root_child2.FlexGrow = 1f;
            root_child2.StyleHeight = 10f;
            root.Insert(2, root_child2);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(100f, root_child0.LayoutWidth);
            Assert.AreEqual(60f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(60f, root_child1.LayoutY);
            Assert.AreEqual(100f, root_child1.LayoutWidth);
            Assert.AreEqual(20f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(80f, root_child2.LayoutY);
            Assert.AreEqual(100f, root_child2.LayoutWidth);
            Assert.AreEqual(20f, root_child2.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(100f, root_child0.LayoutWidth);
            Assert.AreEqual(60f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(60f, root_child1.LayoutY);
            Assert.AreEqual(100f, root_child1.LayoutWidth);
            Assert.AreEqual(20f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(80f, root_child2.LayoutY);
            Assert.AreEqual(100f, root_child2.LayoutWidth);
            Assert.AreEqual(20f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_flex_grow_shrink_at_most()
        {
            CSSNode root = new CSSNode();
            root.StyleWidth = 100f;
            root.StyleHeight = 100f;

            CSSNode root_child0 = new CSSNode();
            root.Insert(0, root_child0);

            CSSNode root_child0_child0 = new CSSNode();
            root_child0_child0.FlexGrow = 1f;
            root_child0_child0.FlexShrink = 1f;
            root_child0.Insert(0, root_child0_child0);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(100f, root_child0.LayoutWidth);
            Assert.AreEqual(0f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child0_child0.LayoutX);
            Assert.AreEqual(0f, root_child0_child0.LayoutY);
            Assert.AreEqual(100f, root_child0_child0.LayoutWidth);
            Assert.AreEqual(0f, root_child0_child0.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(100f, root_child0.LayoutWidth);
            Assert.AreEqual(0f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child0_child0.LayoutX);
            Assert.AreEqual(0f, root_child0_child0.LayoutY);
            Assert.AreEqual(100f, root_child0_child0.LayoutWidth);
            Assert.AreEqual(0f, root_child0_child0.LayoutHeight);
        }

    }
}
