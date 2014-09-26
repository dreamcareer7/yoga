/** @nolint */

var layoutTestUtils = (function() {
  var iframe = (function() {
    var iframe = document.createElement('iframe');
    document.body.appendChild(iframe);
    var doc = iframe.contentDocument;

    var style = document.createElement('style');
    style.innerText = (function() {/*
      body, div {
        box-sizing: border-box;
        border: 0 solid black;
        position: relative;

        display: flex;
        display: -webkit-flex;
        flex-direction: column;
        -webkit-flex-direction: column;
        align-items: flex-start;
        -webkit-align-items: flex-start;
        justify-content: flex-start;
        -webkit-justify-content: flex-start;
        flex-shrink: 0;
        -webkit-flex-shrink: 0;

        margin: 0;
        padding: 0;
      }
    */} + '').slice(15, -4);
    doc.head.appendChild(style);

    return iframe;
  })();
  var body = iframe.contentDocument.body;

  var iframeText = document.createElement('iframe');
  document.body.appendChild(iframeText);

  var realComputeLayout = computeLayout;

  function computeCSSLayout(rootNode) {
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

      if (!node.children || node.style.measure) {
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

    fillNodes(rootNode);
    realComputeLayout(rootNode);
    return extractNodes(rootNode);
  }

  function computeDOMLayout(node) {
    var body = iframe.contentDocument.body;

    function transfer(div, node, name, ext) {
      if (name in node.style) {
        div.style['-webkit-' + name] = node.style[name] + (ext || '');
        div.style[name] = node.style[name] + (ext || '');
      }
    }

    function transferSpacing(div, node, type, suffix) {
      transfer(div, node, type + suffix, 'px');
      transfer(div, node, type + 'Left' + suffix, 'px');
      transfer(div, node, type + 'Top' + suffix, 'px');
      transfer(div, node, type + 'Bottom' + suffix, 'px');
      transfer(div, node, type + 'Right' + suffix, 'px');
    }

    function renderNode(parent, node) {
      var div = document.createElement('div');
      transfer(div, node, 'width', 'px');
      transfer(div, node, 'height', 'px');
      transfer(div, node, 'top', 'px');
      transfer(div, node, 'left', 'px');
      transfer(div, node, 'right', 'px');
      transfer(div, node, 'bottom', 'px');
      transferSpacing(div, node, 'margin', '');
      transferSpacing(div, node, 'padding', '');
      transferSpacing(div, node, 'border', 'Width');
      transfer(div, node, 'flexDirection');
      transfer(div, node, 'flex');
      transfer(div, node, 'justifyContent');
      transfer(div, node, 'alignSelf');
      transfer(div, node, 'alignItems');
      transfer(div, node, 'position');
      parent.appendChild(div);
      (node.children || []).forEach(function(child) {
        renderNode(div, child);
      });
      if (node.style.measure) {
        div.innerText = node.style.measure.toString();
      }
      return div;
    }

    var div = renderNode(body, node);

    function buildLayout(absoluteRect, div) {
      var rect = div.getBoundingClientRect();
      var result = {
        width: rect.width,
        height: rect.height,
        top: rect.top - absoluteRect.top,
        left: rect.left - absoluteRect.left
      };

      var children = [];
      for (var child = div.firstChild; child; child = child.nextSibling) {
        if (child.nodeType !== 3 /* textNode */) {
          children.push(buildLayout(rect, child));
        }
      }
      if (children.length) {
        result.children = children;
      }
      return result;
    }
    var layout = buildLayout({left: 0, top: 0}, div);
    body.removeChild(div);
    return layout;
  }

  function nameLayout(name, layout) {
    var namedLayout = {name: name};
    for (var key in layout) {
      namedLayout[key] = layout[key];
    }
    return namedLayout;
  }

  function testNamedLayout(name, layoutA, layoutB) {
    expect(nameLayout(name, layoutA))
      .toEqual(nameLayout(name, layoutB));
  }

  function isEqual(a, b) {
    // computeCSSLayout and computeDOMLayout output a tree with same ordered elements
    return JSON.stringify(a) === JSON.stringify(b);
  }

  function reduceTest(node) {
    function isWorking() {
      return isEqual(
        computeDOMLayout(node),
        computeCSSLayout(node)
      );
    }
    if (isWorking()) {
      return node;
    }

    var isModified = true;

    function rec(node) {
      // Style
      for (var key in node.style) {
        var value = node.style[key];
        delete node.style[key];
        if (isWorking()) {
          node.style[key] = value;
        } else {
          isModified = true;
        }
      }
      // Round values
      for (var key in node.style) {
        var value = node.style[key];
        if (value > 100) {
          node.style[key] = Math.round(value / 100) * 100;
        } else if (value > 10) {
          node.style[key] = Math.round(value / 10) * 10;
        } else if (value > 1) {
          node.style[key] = 5;
        }
        if (node.style[key] !== value) {
          if (isWorking()) {
            node.style[key] = value;
          } else {
            isModified = true;
          }
        }
      }
      // Children
      for (var i = 0; node.children && i < node.children.length; ++i) {
        var value = node.children[i];
        node.children.splice(i, 1);
        if (isWorking()) {
          if (!node.children) {
            node.children = [];
          }
          node.children.splice(i, 0, value);
          rec(node.children[i]);
        } else {
          i--;
          isModified = true;
        }
      }
    }
    while (isModified) {
      isModified = false;
      rec(node);
    }

    return node;
  }

  function measureTextSizes(text, width) {
    var body = iframeText.contentDocument.body;
    if (width === undefined || width !== width) {
      width = Infinity;
    }

    var div = document.createElement('div');
    div.style.width = (width === Infinity ? 10000000 : width) + 'px';
    div.style.display = 'flex';
    div.style.flexDirection = 'column';
    div.style.alignItems = 'flex-start';

    var span = document.createElement('span');
    span.style.display = 'flex';
    span.style.flexDirection = 'column';
    span.style.alignItems = 'flex-start';
    span.innerText = text;

    div.appendChild(span);
    body.appendChild(div);
    var rect = span.getBoundingClientRect();
    body.removeChild(div);
    return {
      width: rect.width,
      height: rect.height
    };
  }

  var texts = {
    small: 'small',
    big: 'loooooooooong with space',
  };

  var textSizes = {
    smallWidth: measureTextSizes(texts.small, 0).width,
    smallHeight: measureTextSizes(texts.small, 0).height,
    bigWidth: measureTextSizes(texts.big).width,
    bigHeight: measureTextSizes(texts.big, 0).height,
    bigMinWidth: measureTextSizes(texts.big, 0).width,
  };

  return {
    texts: texts,
    textSizes: textSizes,
    testLayout: function(node, expectedLayout) {
      var layout = computeCSSLayout(node);
      var domLayout = computeDOMLayout(node);
      testNamedLayout('expected-dom', expectedLayout, domLayout);
      testNamedLayout('layout-dom', layout, domLayout);
    },
    testRandomLayout: function(node, i) {
      expect({i: i, node: node, layout: computeCSSLayout(node)})
        .toEqual({i: i, node: node, layout: computeDOMLayout(node)});
    },
    testsFinished: function() {
      console.log('tests finished!');
    },
    computeLayout: computeCSSLayout,
    computeDOMLayout: computeDOMLayout,
    reduceTest: reduceTest,
    text: function(text) {
      var fn = function(width) {
        if (width === undefined || width !== width) {
          width = Infinity;
        }

        // Constants for testing purposes between C/JS and other platforms
        // Comment this block of code if you want to use the browser to
        // generate proper sizes
        if (text === texts.small) {
          return {
            width: Math.min(textSizes.smallWidth, width),
            height: textSizes.smallHeight
          };
        }
        if (text === texts.big) {
          var res = {
            width: width >= textSizes.bigWidth ? textSizes.bigWidth : Math.max(textSizes.bigMinWidth, width),
            height: width >= textSizes.bigWidth ? textSizes.smallHeight : textSizes.bigHeight
          };
          return res;
        }
      };
      fn.toString = function() { return text; };
      return fn;
    }
  }
})();
