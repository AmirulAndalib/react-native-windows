/**
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * @format
 * @flow
 */

'use strict';

import type {RNTesterModuleExample} from '../../types/RNTesterTypes';

import {FlatList_BaseOnViewableItemsChanged} from './FlatList-BaseOnViewableItemsChanged';
import * as React from 'react';

export default ({
  title: 'onViewableItemsChanged offScreen',
  name: 'onViewableItemsChanged-offScreen',
  description: 'E2E Test:\nonViewableItemsChanged-offScreen',
  hidden: true,
  render: () => (
    <FlatList_BaseOnViewableItemsChanged
      offScreen={true}
      waitForInteraction={true}
    />
  ),
}: RNTesterModuleExample);