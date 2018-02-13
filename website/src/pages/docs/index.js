/**
 * Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 * @flow
 * @format
 */

import React from 'react';
import Link from 'gatsby-link';
import Page from '../../components/Page';
import Padded from '../../components/Padded';
import {Row, Col} from 'antd';
import './index.css';

const CATEGORY_TITLE = {
  'getting-started': 'Getting Started',
  'properties': 'Properties',
  'examples': 'Examples',
  'contributing': 'Contributing',
};

export default ({data}) => (
  <Page className="docs-landing">
    <Padded>
      <Row className="heading">
        <Col xl={16} lg={16} md={24} sm={24} xs={24}>
          <h1>Documentation</h1>
          <p>
          Welcome to Yoga's documentation page. Below you will find helpfull
          documentation on how to use yoga. As well as how to contribute to the
          core library, documentation, and tests. We have also put together a set
          of examples showing off common layouts and how to user Yoga to achieve them.
          </p>
        </Col>
      </Row>
      <Row>
        {['getting-started', 'properties', 'examples', 'contributing'].map(
          category => (
            <Col lg={6} md={12} xs={24} key={category} className="category">
              <h2>{CATEGORY_TITLE[category]}</h2>
              {data.allMarkdownRemark.edges
                .filter(
                  ({node}) =>
                    node.fileAbsolutePath.indexOf(`/${category}/`) > -1,
                )
                .map(({node}) => (
                  <Link key={node.id} to={node.frontmatter.path}>
                    {node.frontmatter.title}
                  </Link>
                ))}
            </Col>
          ),
        )}
      </Row>
    </Padded>
  </Page>
);

export const query = graphql`
  query IndexQuery {
    allMarkdownRemark {
      edges {
        node {
          id
          frontmatter {
            title
            path
          }
          fileAbsolutePath
        }
      }
    }
  }
`;
