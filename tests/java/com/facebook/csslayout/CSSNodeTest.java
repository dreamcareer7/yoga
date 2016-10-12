/**
 * Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

package com.facebook.csslayout;

import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;

/**
 * Tests for {@link CSSNodeDEPRECATED}.
 */
public class CSSNodeTest {

  @Test
  public void testAddChildGetParent() {
    CSSNodeDEPRECATED parent = new CSSNodeDEPRECATED();
    CSSNodeDEPRECATED child = new CSSNodeDEPRECATED();

    assertNull(child.getParent());
    assertEquals(0, parent.getChildCount());

    parent.addChildAt(child, 0);

    assertEquals(1, parent.getChildCount());
    assertEquals(child, parent.getChildAt(0));
    assertEquals(parent, child.getParent());

    parent.removeChildAt(0);

    assertNull(child.getParent());
    assertEquals(0, parent.getChildCount());
  }

  @Test(expected = IllegalStateException.class)
  public void testCannotAddChildToMultipleParents() {
    CSSNodeDEPRECATED parent1 = new CSSNodeDEPRECATED();
    CSSNodeDEPRECATED parent2 = new CSSNodeDEPRECATED();
    CSSNodeDEPRECATED child = new CSSNodeDEPRECATED();

    parent1.addChildAt(child, 0);
    parent2.addChildAt(child, 0);
  }
}
