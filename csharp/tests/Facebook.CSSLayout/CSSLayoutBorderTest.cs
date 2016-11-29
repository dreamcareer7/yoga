/**
 * Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

 // @Generated by gentest/gentest.rb from gentest/fixtures/CSSLayoutBorderTest.html

using System;
using NUnit.Framework;

namespace Facebook.CSSLayout
{
    [TestFixture]
    public class CSSLayoutBorderTest
    {
        [Test]
        public void Test_border_no_size()
        {
            CSSNode root = new CSSNode();
            root.SetBorder(CSSEdge.Left, 10f);
            root.SetBorder(CSSEdge.Top, 10f);
            root.SetBorder(CSSEdge.Right, 10f);
            root.SetBorder(CSSEdge.Bottom, 10f);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(20f, root.LayoutWidth);
            Assert.AreEqual(20f, root.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(20f, root.LayoutWidth);
            Assert.AreEqual(20f, root.LayoutHeight);
        }

        [Test]
        public void Test_border_container_match_child()
        {
            CSSNode root = new CSSNode();
            root.SetBorder(CSSEdge.Left, 10f);
            root.SetBorder(CSSEdge.Top, 10f);
            root.SetBorder(CSSEdge.Right, 10f);
            root.SetBorder(CSSEdge.Bottom, 10f);

            CSSNode root_child0 = new CSSNode();
            root_child0.Width = 10f;
            root_child0.Height = 10f;
            root.Insert(0, root_child0);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(30f, root.LayoutWidth);
            Assert.AreEqual(30f, root.LayoutHeight);

            Assert.AreEqual(10f, root_child0.LayoutX);
            Assert.AreEqual(10f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(30f, root.LayoutWidth);
            Assert.AreEqual(30f, root.LayoutHeight);

            Assert.AreEqual(10f, root_child0.LayoutX);
            Assert.AreEqual(10f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);
        }

        [Test]
        public void Test_border_flex_child()
        {
            CSSNode root = new CSSNode();
            root.SetBorder(CSSEdge.Left, 10f);
            root.SetBorder(CSSEdge.Top, 10f);
            root.SetBorder(CSSEdge.Right, 10f);
            root.SetBorder(CSSEdge.Bottom, 10f);
            root.Width = 100f;
            root.Height = 100f;

            CSSNode root_child0 = new CSSNode();
            root_child0.FlexGrow = 1f;
            root_child0.Width = 10f;
            root.Insert(0, root_child0);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(10f, root_child0.LayoutX);
            Assert.AreEqual(10f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(80f, root_child0.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(80f, root_child0.LayoutX);
            Assert.AreEqual(10f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(80f, root_child0.LayoutHeight);
        }

        [Test]
        public void Test_border_stretch_child()
        {
            CSSNode root = new CSSNode();
            root.SetBorder(CSSEdge.Left, 10f);
            root.SetBorder(CSSEdge.Top, 10f);
            root.SetBorder(CSSEdge.Right, 10f);
            root.SetBorder(CSSEdge.Bottom, 10f);
            root.Width = 100f;
            root.Height = 100f;

            CSSNode root_child0 = new CSSNode();
            root_child0.Height = 10f;
            root.Insert(0, root_child0);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(10f, root_child0.LayoutX);
            Assert.AreEqual(10f, root_child0.LayoutY);
            Assert.AreEqual(80f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(10f, root_child0.LayoutX);
            Assert.AreEqual(10f, root_child0.LayoutY);
            Assert.AreEqual(80f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);
        }

        [Test]
        public void Test_border_center_child()
        {
            CSSNode root = new CSSNode();
            root.JustifyContent = CSSJustify.Center;
            root.AlignItems = CSSAlign.Center;
            root.SetBorder(CSSEdge.Start, 10f);
            root.SetBorder(CSSEdge.End, 20f);
            root.SetBorder(CSSEdge.Bottom, 20f);
            root.Width = 100f;
            root.Height = 100f;

            CSSNode root_child0 = new CSSNode();
            root_child0.Width = 10f;
            root_child0.Height = 10f;
            root.Insert(0, root_child0);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(40f, root_child0.LayoutX);
            Assert.AreEqual(35f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(100f, root.LayoutWidth);
            Assert.AreEqual(100f, root.LayoutHeight);

            Assert.AreEqual(50f, root_child0.LayoutX);
            Assert.AreEqual(35f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);
        }

    }
}
