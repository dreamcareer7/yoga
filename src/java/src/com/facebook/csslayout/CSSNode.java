/**
 * Copyright (c) 2014, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */
package com.facebook.csslayout;

import java.util.ArrayList;

/**
 * A CSS Node. It has a style object you can manipulate at {@link #style}. After calling
 * {@link #calculateLayout()}, {@link #layout} will be filled with the results of the layout.
 */
public class CSSNode {

  private static enum LayoutState {
    /**
     * Some property of this node or its children has changes and the current values in
     * {@link #layout} are not valid.
     */
    DIRTY,

    /**
     * This node has a new layout relative to the last time {@link #markLayoutSeen()} was called.
     */
    HAS_NEW_LAYOUT,

    /**
     * {@link #layout} is valid for the node's properties and this layout has been marked as
     * having been seen.
     */
    UP_TO_DATE,
  }

  // Only one copy kept around to keep from allocating a bunch of MeasureOutput objects
  // NOT THREAD SAFE! NOT RE-ENTRANT SAFE!
  private static final MeasureOutput MEASURE_OUTPUT = new MeasureOutput();

  public static interface MeasureFunction {

    /**
     * Should measure the given node and put the result in the given MeasureOutput.
     *
     * NB: measure is NOT guaranteed to be threadsafe/re-entrant safe!
     */
    public void measure(CSSNode node, float width, MeasureOutput measureOutput);
  }

  // VisibleForTesting
  /*package*/ final CSSStyle style = new CSSStyle();
  /*package*/ final CSSLayout layout = new CSSLayout();
  /*package*/ final CachedCSSLayout lastLayout = new CachedCSSLayout();

  // 4 is kinda arbitrary, but the default of 10 seems really high for an average View.
  private final ArrayList<CSSNode> mChildren = new ArrayList<CSSNode>(4);

  private CSSNode mParent;
  private MeasureFunction mMeasureFunction = null;
  private LayoutState mLayoutState = LayoutState.DIRTY;

  public int getChildCount() {
    return mChildren.size();
  }

  public CSSNode getChildAt(int i) {
    return mChildren.get(i);
  }

  public void addChildAt(CSSNode child, int i) {
    if (child.mParent != null) {
      throw new IllegalStateException("Child already has a parent, it must be removed first.");
    }

    mChildren.add(i, child);
    child.mParent = this;
    dirty();
  }

  public void removeChildAt(int i) {
    mChildren.remove(i).mParent = null;
    dirty();
  }

  public CSSNode getParent() {
    return mParent;
  }

  public void setMeasureFunction(MeasureFunction measureFunction) {
    if (!valuesEqual(mMeasureFunction, measureFunction)) {
      mMeasureFunction = measureFunction;
      dirty();
    }
  }

  public boolean isMeasureDefined() {
    return mMeasureFunction != null;
  }

  /*package*/ MeasureOutput measure(float width) {
    if (!isMeasureDefined()) {
      throw new RuntimeException("Measure function isn't defined!");
    }
    MEASURE_OUTPUT.height = CSSConstants.UNDEFINED;
    MEASURE_OUTPUT.width = CSSConstants.UNDEFINED;
    mMeasureFunction.measure(this, width, MEASURE_OUTPUT);
    return MEASURE_OUTPUT;
  }

  /**
   * Performs the actual layout and saves the results in {@link #layout}
   */
  public void calculateLayout() {
    resetLayoutResultRecursive();
    LayoutEngine.layoutNode(this, CSSConstants.UNDEFINED);
  }

  /**
   * See {@link LayoutState#DIRTY}.
   */
  /*package*/ boolean isDirty() {
    return mLayoutState == LayoutState.DIRTY;
  }

  /**
   * See {@link LayoutState#HAS_NEW_LAYOUT}.
   */
  public boolean hasNewLayout() {
    return mLayoutState == LayoutState.HAS_NEW_LAYOUT;
  }

  protected void dirty() {
    if (mLayoutState == LayoutState.DIRTY) {
      return;
    } else if (mLayoutState == LayoutState.HAS_NEW_LAYOUT) {
      throw new IllegalStateException("Previous layout was ignored! markLayoutSeen() never called");
    }

    mLayoutState = LayoutState.DIRTY;

    if (mParent != null) {
      mParent.dirty();
    }
  }

  /*package*/ void markHasNewLayout() {
    mLayoutState = LayoutState.HAS_NEW_LAYOUT;
  }

  /**
   * Tells the node that the current values in {@link #layout} have been seen. Subsequent calls
   * to {@link #hasNewLayout()} will return false until this node is laid out with new parameters.
   * You must call this each time the layout is generated if the node has a new layout.
   */
  public void markLayoutSeen() {
    if (!hasNewLayout()) {
      throw new IllegalStateException("Expected node to have a new layout to be seen!");
    }

    mLayoutState = LayoutState.UP_TO_DATE;
  }

  @Override
  public String toString() {
    String layoutString = layout.toString();

    if (getChildCount() == 0) {
      return layoutString;
    }

    layoutString += ", children: [\n";

    for (int i = 0; i < getChildCount(); i++) {
      String childString = getChildAt(i).toString();
      childString = childString.replaceAll("\n", "\n\t");
      layoutString += "\t" + childString + "\n";
    }

    layoutString += "]";

    return layoutString;
  }

  private void resetLayoutResultRecursive() {
    layout.resetResult();
    for (int i = 0; i < getChildCount(); i++) {
      getChildAt(i).resetLayoutResultRecursive();
    }
  }

  protected boolean valuesEqual(float f1, float f2) {
    return FloatUtil.floatsEqual(f1, f2);
  }

  protected <T> boolean valuesEqual(T o1, T o2) {
    if (o1 == null) {
      return o2 == null;
    }
    return o1.equals(o2);
  }

  public void setFlexDirection(CSSFlexDirection flexDirection) {
    if (!valuesEqual(style.flexDirection, flexDirection)) {
      style.flexDirection = flexDirection;
      dirty();
    }
  }

  public void setJustifyContent(CSSJustify justifyContent) {
    if (!valuesEqual(style.justifyContent, justifyContent)) {
      style.justifyContent = justifyContent;
      dirty();
    }
  }

  public void setAlignItems(CSSAlign alignItems) {
    if (!valuesEqual(style.alignItems, alignItems)) {
      style.alignItems = alignItems;
      dirty();
    }
  }

  public void setAlignSelf(CSSAlign alignSelf) {
    if (!valuesEqual(style.alignSelf, alignSelf)) {
      style.alignSelf = alignSelf;
      dirty();
    }
  }

  public void setPositionType(CSSPositionType positionType) {
    if (!valuesEqual(style.positionType, positionType)) {
      style.positionType = positionType;
      dirty();
    }
  }

  public void setFlex(float flex) {
    if (!valuesEqual(style.flex, flex)) {
      style.flex = flex;
      dirty();
    }
  }

  public void setMarginTop(float marginTop) {
    if (!valuesEqual(style.marginTop, marginTop)) {
      style.marginTop = marginTop;
      dirty();
    }
  }

  public void setMarginBottom(float marginBottom) {
    if (!valuesEqual(style.marginBottom, marginBottom)) {
      style.marginBottom = marginBottom;
      dirty();
    }
  }

  public void setMarginLeft(float marginLeft) {
    if (!valuesEqual(style.marginLeft, marginLeft)) {
      style.marginLeft = marginLeft;
      dirty();
    }
  }

  public void setMarginRight(float marginRight) {
    if (!valuesEqual(style.marginRight, marginRight)) {
      style.marginRight = marginRight;
      dirty();
    }
  }

  public void setPaddingTop(float paddingTop) {
    if (!valuesEqual(style.paddingTop, paddingTop)) {
      style.paddingTop = paddingTop;
      dirty();
    }
  }

  public void setPaddingBottom(float paddingBottom) {
    if (!valuesEqual(style.paddingBottom, paddingBottom)) {
      style.paddingBottom = paddingBottom;
      dirty();
    }
  }

  public void setPaddingLeft(float paddingLeft) {
    if (!valuesEqual(style.paddingLeft, paddingLeft)) {
      style.paddingLeft = paddingLeft;
      dirty();
    }
  }

  public void setPaddingRight(float paddingRight) {
    if (!valuesEqual(style.paddingRight, paddingRight)) {
      style.paddingRight = paddingRight;
      dirty();
    }
  }

  public void setPositionTop(float positionTop) {
    if (!valuesEqual(style.positionTop, positionTop)) {
      style.positionTop = positionTop;
      dirty();
    }
  }

  public void setPositionBottom(float positionBottom) {
    if (!valuesEqual(style.positionBottom, positionBottom)) {
      style.positionBottom = positionBottom;
      dirty();
    }
  }

  public void setPositionLeft(float positionLeft) {
    if (!valuesEqual(style.positionLeft, positionLeft)) {
      style.positionLeft = positionLeft;
      dirty();
    }
  }

  public void setPositionRight(float positionRight) {
    if (!valuesEqual(style.positionRight, positionRight)) {
      style.positionRight = positionRight;
      dirty();
    }
  }

  public void setBorderTop(float borderTop) {
    if (!valuesEqual(style.borderTop, borderTop)) {
      style.borderTop = borderTop;
      dirty();
    }
  }

  public void setBorderBottom(float borderBottom) {
    if (!valuesEqual(style.borderBottom, borderBottom)) {
      style.borderBottom = borderBottom;
      dirty();
    }
  }

  public void setBorderLeft(float borderLeft) {
    if (!valuesEqual(style.borderLeft, borderLeft)) {
      style.borderLeft = borderLeft;
      dirty();
    }
  }

  public void setBorderRight(float borderRight) {
    if (!valuesEqual(style.borderRight, borderRight)) {
      style.borderRight = borderRight;
      dirty();
    }
  }

  public void setStyleWidth(float width) {
    if (!valuesEqual(style.width, width)) {
      style.width = width;
      dirty();
    }
  }

  public void setStyleHeight(float height) {
    if (!valuesEqual(style.height, height)) {
      style.height = height;
      dirty();
    }
  }

  public float getLayoutX() {
    return layout.x;
  }

  public float getLayoutY() {
    return layout.y;
  }

  public float getLayoutWidth() {
    return layout.width;
  }

  public float getLayoutHeight() {
    return layout.height;
  }
}
