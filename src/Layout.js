
var computeLayout = (function() {

  function fillNodes(node) {
    node.layout = {
      width: undefined,
      height: undefined,
      top: 0,
      left: 0
    };
    if (!node.style) {
      node.style = {};
    }
    if (!node.children) {
      node.children = [];
    }
    node.children.forEach(fillNodes);
  }

  function extractNodes(node) {
    var layout = node.layout;
    delete node.layout;
    if (node.children.length > 0) {
      layout.children = node.children.map(extractNodes);
    } else {
      delete node.children;
    }
    return layout;
  }

  function capitalizeFirst(str) {
    return str.charAt(0).toUpperCase() + str.slice(1);
  }

  function getSpacing(node, type, suffix, location) {
    var key = type + capitalizeFirst(location) + suffix;
    if (key in node.style) {
      return node.style[key];
    }

    key = type + suffix;
    if (key in node.style) {
      return node.style[key];
    }

    return 0;
  }

  function getPositiveSpacing(node, type, suffix, location) {
    var key = type + capitalizeFirst(location) + suffix;
    if (key in node.style && node.style[key] >= 0) {
      return node.style[key];
    }

    key = type + suffix;
    if (key in node.style && node.style[key] >= 0) {
      return node.style[key];
    }

    return 0;
  }

  function isUndefined(value) {
    return value === undefined;
  }

  function getMargin(node, location) {
    return getSpacing(node, 'margin', '', location);
  }

  function getPadding(node, location) {
    return getPositiveSpacing(node, 'padding', '', location);
  }

  function getBorder(node, location) {
    return getPositiveSpacing(node, 'border', 'Width', location);
  }

  function getPaddingAndBorder(node, location) {
    return getPadding(node, location) + getBorder(node, location);
  }

  function getMarginAxis(node, axis) {
    return getMargin(node, leading[axis]) + getMargin(node, trailing[axis]);
  }

  function getPaddingAndBorderAxis(node, axis) {
    return getPaddingAndBorder(node, leading[axis]) + getPaddingAndBorder(node, trailing[axis]);
  }

  function getJustifyContent(node) {
    if ('justifyContent' in node.style) {
      return node.style.justifyContent;
    }
    return 'flex-start';
  }

  function getAlignItem(node, child) {
    if ('alignSelf' in child.style) {
      return child.style.alignSelf;
    }
    if ('alignItems' in node.style) {
      return node.style.alignItems;
    }
    return 'flex-start';
  }

  function getFlexDirection(node) {
    if ('flexDirection' in node.style) {
      return node.style.flexDirection;
    }
    return 'column';
  }

  function getPositionType(node) {
    if ('position' in node.style) {
      return node.style.position;
    }
    return 'relative';
  }

  function getFlex(node) {
    return node.style.flex === 1;
  }

  function isFlex(node) {
    return getPositionType(node) === CSS_POSITION_RELATIVE && getFlex(node);
  }

  function getDimWithMargin(node, axis) {
    return node.layout[dim[axis]] + getMarginAxis(node, axis);
  }

  function isDimDefined(node, axis) {
    return !isUndefined(node.style[dim[axis]]) && node.style[dim[axis]] >= 0;
  }

  function isPosDefined(node, pos) {
    return !isUndefined(node.style[pos]);
  }

  function getPosition(node, pos) {
    if (pos in node.style) {
      return node.style[pos];
    }
    return 0;
  }


  // This function handles when the user specifically sets a value
  // for `width` or `height`
  function setDimension(node, axis) {
    // The parent already computed us a width or height. We just skip it
    if (!isUndefined(node.layout[dim[axis]])) {
      return;
    }
    // We only run if there's a width or height defined
    if (!isDimDefined(node, axis)) {
      return;
    }

    // The dimensions can never be smaller than the padding and border
    node.layout[dim[axis]] = fmaxf(
      node.style[dim[axis]],
      getPaddingAndBorderAxis(node, axis)
    );
  }

  // If both left and right are defined, then use left. Otherwise return
  // +left or -right depending on which is defined.
  function getRelativePosition(node, axis) {
    if (leading[axis] in node.style) {
      return getPosition(node, leading[axis]);
    }
    return -getPosition(node, trailing[axis]);
  }

  var leading = {
    row: 'left',
    column: 'top'
  };
  var trailing = {
    row: 'right',
    column: 'bottom'
  };
  var pos = {
    row: 'left',
    column: 'top'
  };
  var dim = {
    row: 'width',
    column: 'height'
  };

  function fmaxf(a, b) {
    if (a > b) {
      return a;
    }
    return b;
  }

  var CSS_FLEX_DIRECTION_ROW = 'row';
  var CSS_FLEX_DIRECTION_COLUMN = 'column';

  var CSS_JUSTIFY_FLEX_START = 'flex-start';
  var CSS_JUSTIFY_CENTER = 'center';
  var CSS_JUSTIFY_FLEX_END = 'flex-end';
  var CSS_JUSTIFY_SPACE_BETWEEN = 'space-between';
  var CSS_JUSTIFY_SPACE_AROUND = 'space-around';

  var CSS_ALIGN_FLEX_START = 'flex-start';
  var CSS_ALIGN_CENTER = 'center';
  var CSS_ALIGN_FLEX_END = 'flex-end';
  var CSS_ALIGN_STRETCH = 'stretch';

  var CSS_POSITION_RELATIVE = 'relative';
  var CSS_POSITION_ABSOLUTE = 'absolute';

  function layoutNode(node) {
    var/*css_flex_direction_t*/ mainAxis = getFlexDirection(node);
    var/*css_flex_direction_t*/ crossAxis = mainAxis === CSS_FLEX_DIRECTION_ROW ?
      CSS_FLEX_DIRECTION_COLUMN :
      CSS_FLEX_DIRECTION_ROW;

    // Handle width and height attributes
    setDimension(node, mainAxis);
    setDimension(node, crossAxis);

    // The algorithm is divided into two main steps:
    // (1) We first layout all the children that aren't flexible
    // (2) At this point, we know the total size and the size of all the non
    //     flexible children. We can now set the dimensions of the flexible
    //     children


    // <Loop A> Layout non flexible children and count children by type

    // mainContentDim is accumulation of the dimensions and margin of all the
    // non flexible children. This will be used in order to either set the
    // dimensions of the node if none already exist, or to compute the
    // remaining space left for the flexible children.
    var/*float*/ mainContentDim = 0;

    // There are three kind of children, non flexible, flexible and absolute.
    // We need to know how many there are in order to distribute the space.
    var/*int*/ flexibleChildrenCount = 0;
    var/*int*/ nonFlexibleChildrenCount = 0;
    for (var/*int*/ i = 0; i < node.children.length; ++i) {
      var/*css_node_t**/ child = node.children[i];

      // It only makes sense to consider a child flexible if we have a computed
      // dimension for the node.
      if (!isUndefined(node.layout[dim[mainAxis]]) && isFlex(child)) {
        flexibleChildrenCount++;

        // Even if we don't know its exact size yet, we already know the padding,
        // border and margin. We'll use this partial information to compute the
        // remaining space.
        mainContentDim += getPaddingAndBorderAxis(child, mainAxis) +
          getMarginAxis(child, mainAxis);

      } else {
        // This is the main recursive call. We layout non flexible children.
        layoutNode(child);

        // Absolute positioned elements do not take part of the layout, so we
        // don't use them to compute mainContentDim
        if (getPositionType(child) === CSS_POSITION_RELATIVE) {
          nonFlexibleChildrenCount++;
          // At this point we know the final size and margin of the element.
          mainContentDim += getDimWithMargin(child, mainAxis);
        }
      }
    }

    // <Loop B> Layout flexible children and allocate empty space

    // In order to position the elements in the main axis, we have two
    // controls. The space between the beginning and the first element
    // and the space between each two elements.
    var/*float*/ leadingMainDim = 0;
    var/*float*/ betweenMainDim = 0;

    // If the dimensions of the current node is defined by its children, they
    // are all going to be packed together and we don't need to compute
    // anything.
    if (!isUndefined(node.layout[dim[mainAxis]])) {

      // The remaining available space that's needs to be allocated
      var/*float*/ remainingMainDim = node.layout[dim[mainAxis]] -
        getPaddingAndBorderAxis(node, mainAxis) -
        mainContentDim;

      // If there are flexible children in the mix, they are going to fill the
      // remaining space
      if (flexibleChildrenCount) {
        var/*float*/ flexibleMainDim = remainingMainDim / flexibleChildrenCount;

        // The non flexible children can overflow the container, in this case
        // we should just assume that there is no space available.
        if (flexibleMainDim < 0) {
          flexibleMainDim = 0;
        }
        // We iterate over the full array and only apply the action on flexible
        // children. This is faster than actually allocating a new array that
        // contains only flexible children.
        for (var/*int*/ i = 0; i < node.children.length; ++i) {
          var/*css_node_t**/ child = node.children[i];
          if (isFlex(child)) {
            // At this point we know the final size of the element in the main
            // dimension
            child.layout[dim[mainAxis]] = flexibleMainDim +
              getPaddingAndBorderAxis(child, mainAxis);

            // And we recursively call the layout algorithm for this child
            layoutNode(child);
          }
        }

      // We use justifyContent to figure out how to allocate the remaining
      // space available
      } else {
        var/*css_justify_t*/ justifyContent = getJustifyContent(node);
        if (justifyContent === CSS_JUSTIFY_FLEX_START) {
          // Do nothing
        } else if (justifyContent === CSS_JUSTIFY_CENTER) {
          leadingMainDim = remainingMainDim / 2;
        } else if (justifyContent === CSS_JUSTIFY_FLEX_END) {
          leadingMainDim = remainingMainDim;
        } else if (justifyContent === CSS_JUSTIFY_SPACE_BETWEEN) {
          betweenMainDim = remainingMainDim /
            (flexibleChildrenCount + nonFlexibleChildrenCount - 1);
        } else if (justifyContent === CSS_JUSTIFY_SPACE_AROUND) {
          // Space on the edges is half of the space between elements
          betweenMainDim = remainingMainDim /
            (flexibleChildrenCount + nonFlexibleChildrenCount);
          leadingMainDim = betweenMainDim / 2;
        }
      }
    }

    var/*float*/ crossDim = 0;
    var/*float*/ mainPos = getPaddingAndBorder(node, leading[mainAxis]) + leadingMainDim;
    for (var/*int*/ i = 0; i < node.children.length; ++i) {
      var/*css_node_t**/ child = node.children[i];
      if (getPositionType(child) === CSS_POSITION_ABSOLUTE && isPosDefined(child, leading[mainAxis])) {
        child.layout[pos[mainAxis]] = getPosition(child, leading[mainAxis]) +
          getBorder(node, leading[mainAxis]) +
          getMargin(child, leading[mainAxis]);
      } else {
        child.layout[pos[mainAxis]] += mainPos;
      }
      if (getPositionType(child) === CSS_POSITION_RELATIVE) {
        mainPos += getDimWithMargin(child, mainAxis) + betweenMainDim;

        if (!isUndefined(child.layout[dim[crossAxis]])) {
          var/*float*/ childCrossDim = getDimWithMargin(child, crossAxis);
          if (childCrossDim > crossDim) {
            crossDim = childCrossDim;
          }
        }
      }
    }

    mainPos += getPaddingAndBorder(node, trailing[mainAxis]);
    crossDim += getPaddingAndBorderAxis(node, crossAxis);

    if (isUndefined(node.layout[dim[mainAxis]]) && !isDimDefined(node, mainAxis)) {
      node.layout[dim[mainAxis]] = fmaxf(mainPos, getPaddingAndBorderAxis(node, mainAxis));
    }
    if (isUndefined(node.layout[dim[crossAxis]])) {
      node.layout[dim[crossAxis]] = fmaxf(crossDim, getPaddingAndBorderAxis(node, crossAxis));
    }

    for (var/*int*/ i = 0; i < node.children.length; ++i) {
      var/*css_node_t**/ child = node.children[i];

      if (getPositionType(child) === CSS_POSITION_RELATIVE) {
        var/*css_align_t*/ alignItem = getAlignItem(node, child);
        var/*float*/ remainingCrossDim = node.layout[dim[crossAxis]] -
          getDimWithMargin(child, crossAxis) -
          getPaddingAndBorderAxis(node, crossAxis);

        var/*float*/ leadingCrossDim = getPaddingAndBorder(node, leading[crossAxis]);
        if (alignItem === CSS_ALIGN_FLEX_START) {
          // Do nothing
        } else if (alignItem === CSS_ALIGN_CENTER) {
          leadingCrossDim += remainingCrossDim / 2;
        } else if (alignItem === CSS_ALIGN_FLEX_END) {
          leadingCrossDim += remainingCrossDim;
        } else if (alignItem === CSS_ALIGN_STRETCH) {
          if (!isDimDefined(child, crossAxis)) {
            child.layout[dim[crossAxis]] = fmaxf(
              node.layout[dim[crossAxis]] -
                getPaddingAndBorderAxis(node, crossAxis) -
                getMarginAxis(child, crossAxis),
              getPaddingAndBorderAxis(child, crossAxis)
            );
          }
        }
        child.layout[pos[crossAxis]] += leadingCrossDim;
      } else {
        if (isPosDefined(child, leading[crossAxis])) {
          child.layout[pos[crossAxis]] = getPosition(child, leading[crossAxis]) +
            getBorder(node, leading[crossAxis]) +
            getMargin(child, leading[crossAxis]);
        } else {
          child.layout[pos[crossAxis]] += getPaddingAndBorder(node, leading[crossAxis]);
        }
      }
    }

    node.layout[leading[mainAxis]] += getMargin(node, leading[mainAxis]) +
      getRelativePosition(node, mainAxis);
    node.layout[leading[crossAxis]] += getMargin(node, leading[crossAxis]) +
      getRelativePosition(node, crossAxis);
  }

  var fn = function(node) {
    fillNodes(node);
    layoutNode(node);
    return extractNodes(node);
  };
  fn.layoutNode = layoutNode;
  return fn;
})();


