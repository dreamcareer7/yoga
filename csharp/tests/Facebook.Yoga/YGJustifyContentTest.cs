/**
 * Copyright (c) 2014-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @Generated by gentest/gentest.rb from gentest/fixtures/YGJustifyContentTest.html

using System;
using NUnit.Framework;

namespace Facebook.Yoga
{
    [TestFixture]
    public class YGJustifyContentTest
    {
        [Test]
        public void Test_justify_content_row_flex_start()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.FlexDirection = YogaFlexDirection.Row;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Width = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Width = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Width = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(102f, root_child0.LayoutHeight);

            Assert.AreEqual(10f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(10f, root_child1.LayoutWidth);
            Assert.AreEqual(102f, root_child1.LayoutHeight);

            Assert.AreEqual(20f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(10f, root_child2.LayoutWidth);
            Assert.AreEqual(102f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(92f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(102f, root_child0.LayoutHeight);

            Assert.AreEqual(82f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(10f, root_child1.LayoutWidth);
            Assert.AreEqual(102f, root_child1.LayoutHeight);

            Assert.AreEqual(72f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(10f, root_child2.LayoutWidth);
            Assert.AreEqual(102f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_row_flex_end()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.FlexDirection = YogaFlexDirection.Row;
            root.JustifyContent = YogaJustify.FlexEnd;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Width = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Width = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Width = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(72f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(102f, root_child0.LayoutHeight);

            Assert.AreEqual(82f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(10f, root_child1.LayoutWidth);
            Assert.AreEqual(102f, root_child1.LayoutHeight);

            Assert.AreEqual(92f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(10f, root_child2.LayoutWidth);
            Assert.AreEqual(102f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(20f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(102f, root_child0.LayoutHeight);

            Assert.AreEqual(10f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(10f, root_child1.LayoutWidth);
            Assert.AreEqual(102f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(10f, root_child2.LayoutWidth);
            Assert.AreEqual(102f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_row_center()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.FlexDirection = YogaFlexDirection.Row;
            root.JustifyContent = YogaJustify.Center;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Width = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Width = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Width = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(36f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(102f, root_child0.LayoutHeight);

            Assert.AreEqual(46f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(10f, root_child1.LayoutWidth);
            Assert.AreEqual(102f, root_child1.LayoutHeight);

            Assert.AreEqual(56f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(10f, root_child2.LayoutWidth);
            Assert.AreEqual(102f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(56f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(102f, root_child0.LayoutHeight);

            Assert.AreEqual(46f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(10f, root_child1.LayoutWidth);
            Assert.AreEqual(102f, root_child1.LayoutHeight);

            Assert.AreEqual(36f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(10f, root_child2.LayoutWidth);
            Assert.AreEqual(102f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_row_space_between()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.FlexDirection = YogaFlexDirection.Row;
            root.JustifyContent = YogaJustify.SpaceBetween;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Width = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Width = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Width = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(102f, root_child0.LayoutHeight);

            Assert.AreEqual(46f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(10f, root_child1.LayoutWidth);
            Assert.AreEqual(102f, root_child1.LayoutHeight);

            Assert.AreEqual(92f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(10f, root_child2.LayoutWidth);
            Assert.AreEqual(102f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(92f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(102f, root_child0.LayoutHeight);

            Assert.AreEqual(46f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(10f, root_child1.LayoutWidth);
            Assert.AreEqual(102f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(10f, root_child2.LayoutWidth);
            Assert.AreEqual(102f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_row_space_around()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.FlexDirection = YogaFlexDirection.Row;
            root.JustifyContent = YogaJustify.SpaceAround;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Width = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Width = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Width = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(12f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(102f, root_child0.LayoutHeight);

            Assert.AreEqual(46f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(10f, root_child1.LayoutWidth);
            Assert.AreEqual(102f, root_child1.LayoutHeight);

            Assert.AreEqual(80f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(10f, root_child2.LayoutWidth);
            Assert.AreEqual(102f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(80f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(10f, root_child0.LayoutWidth);
            Assert.AreEqual(102f, root_child0.LayoutHeight);

            Assert.AreEqual(46f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(10f, root_child1.LayoutWidth);
            Assert.AreEqual(102f, root_child1.LayoutHeight);

            Assert.AreEqual(12f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(10f, root_child2.LayoutWidth);
            Assert.AreEqual(102f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_column_flex_start()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Height = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Height = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Height = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(10f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(20f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(10f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(20f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_column_flex_end()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.JustifyContent = YogaJustify.FlexEnd;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Height = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Height = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Height = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(72f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(82f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(92f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(72f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(82f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(92f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_column_center()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.JustifyContent = YogaJustify.Center;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Height = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Height = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Height = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(36f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(46f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(56f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(36f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(46f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(56f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_column_space_between()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.JustifyContent = YogaJustify.SpaceBetween;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Height = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Height = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Height = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(46f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(92f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(46f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(92f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_column_space_around()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.JustifyContent = YogaJustify.SpaceAround;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Height = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Height = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Height = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(12f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(46f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(80f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(12f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(46f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(80f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_row_min_width_and_margin()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.FlexDirection = YogaFlexDirection.Row;
            root.JustifyContent = YogaJustify.Center;
            root.MarginLeft = 100;
            root.MinWidth = 50;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Width = 20;
            root_child0.Height = 20;
            root.Insert(0, root_child0);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(100f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(50f, root.LayoutWidth);
            Assert.AreEqual(20f, root.LayoutHeight);

            Assert.AreEqual(15f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(20f, root_child0.LayoutWidth);
            Assert.AreEqual(20f, root_child0.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(100f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(50f, root.LayoutWidth);
            Assert.AreEqual(20f, root.LayoutHeight);

            Assert.AreEqual(15f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(20f, root_child0.LayoutWidth);
            Assert.AreEqual(20f, root_child0.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_row_max_width_and_margin()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.FlexDirection = YogaFlexDirection.Row;
            root.JustifyContent = YogaJustify.Center;
            root.MarginLeft = 100;
            root.Width = 100;
            root.MaxWidth = 80;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Width = 20;
            root_child0.Height = 20;
            root.Insert(0, root_child0);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(100f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(80f, root.LayoutWidth);
            Assert.AreEqual(20f, root.LayoutHeight);

            Assert.AreEqual(30f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(20f, root_child0.LayoutWidth);
            Assert.AreEqual(20f, root_child0.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(100f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(80f, root.LayoutWidth);
            Assert.AreEqual(20f, root.LayoutHeight);

            Assert.AreEqual(30f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(20f, root_child0.LayoutWidth);
            Assert.AreEqual(20f, root_child0.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_column_min_height_and_margin()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.JustifyContent = YogaJustify.Center;
            root.MarginTop = 100;
            root.MinHeight = 50;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Width = 20;
            root_child0.Height = 20;
            root.Insert(0, root_child0);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(100f, root.LayoutY);
            Assert.AreEqual(20f, root.LayoutWidth);
            Assert.AreEqual(50f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(15f, root_child0.LayoutY);
            Assert.AreEqual(20f, root_child0.LayoutWidth);
            Assert.AreEqual(20f, root_child0.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(100f, root.LayoutY);
            Assert.AreEqual(20f, root.LayoutWidth);
            Assert.AreEqual(50f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(15f, root_child0.LayoutY);
            Assert.AreEqual(20f, root_child0.LayoutWidth);
            Assert.AreEqual(20f, root_child0.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_colunn_max_height_and_margin()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.JustifyContent = YogaJustify.Center;
            root.MarginTop = 100;
            root.Height = 100;
            root.MaxHeight = 80;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Width = 20;
            root_child0.Height = 20;
            root.Insert(0, root_child0);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(100f, root.LayoutY);
            Assert.AreEqual(20f, root.LayoutWidth);
            Assert.AreEqual(80f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(30f, root_child0.LayoutY);
            Assert.AreEqual(20f, root_child0.LayoutWidth);
            Assert.AreEqual(20f, root_child0.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(100f, root.LayoutY);
            Assert.AreEqual(20f, root.LayoutWidth);
            Assert.AreEqual(80f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(30f, root_child0.LayoutY);
            Assert.AreEqual(20f, root_child0.LayoutWidth);
            Assert.AreEqual(20f, root_child0.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_column_space_evenly()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.JustifyContent = YogaJustify.SpaceEvenly;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Height = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Height = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Height = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(18f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(46f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(74f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(0f, root_child0.LayoutX);
            Assert.AreEqual(18f, root_child0.LayoutY);
            Assert.AreEqual(102f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(0f, root_child1.LayoutX);
            Assert.AreEqual(46f, root_child1.LayoutY);
            Assert.AreEqual(102f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(0f, root_child2.LayoutX);
            Assert.AreEqual(74f, root_child2.LayoutY);
            Assert.AreEqual(102f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);
        }

        [Test]
        public void Test_justify_content_row_space_evenly()
        {
            YogaConfig config = new YogaConfig();

            YogaNode root = new YogaNode(config);
            root.FlexDirection = YogaFlexDirection.Row;
            root.JustifyContent = YogaJustify.SpaceEvenly;
            root.Width = 102;
            root.Height = 102;

            YogaNode root_child0 = new YogaNode(config);
            root_child0.Height = 10;
            root.Insert(0, root_child0);

            YogaNode root_child1 = new YogaNode(config);
            root_child1.Height = 10;
            root.Insert(1, root_child1);

            YogaNode root_child2 = new YogaNode(config);
            root_child2.Height = 10;
            root.Insert(2, root_child2);
            root.StyleDirection = YogaDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(26f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(0f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(51f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(0f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(77f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(0f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);

            root.StyleDirection = YogaDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0f, root.LayoutX);
            Assert.AreEqual(0f, root.LayoutY);
            Assert.AreEqual(102f, root.LayoutWidth);
            Assert.AreEqual(102f, root.LayoutHeight);

            Assert.AreEqual(77f, root_child0.LayoutX);
            Assert.AreEqual(0f, root_child0.LayoutY);
            Assert.AreEqual(0f, root_child0.LayoutWidth);
            Assert.AreEqual(10f, root_child0.LayoutHeight);

            Assert.AreEqual(51f, root_child1.LayoutX);
            Assert.AreEqual(0f, root_child1.LayoutY);
            Assert.AreEqual(0f, root_child1.LayoutWidth);
            Assert.AreEqual(10f, root_child1.LayoutHeight);

            Assert.AreEqual(26f, root_child2.LayoutX);
            Assert.AreEqual(0f, root_child2.LayoutY);
            Assert.AreEqual(0f, root_child2.LayoutWidth);
            Assert.AreEqual(10f, root_child2.LayoutHeight);
        }

    }
}
