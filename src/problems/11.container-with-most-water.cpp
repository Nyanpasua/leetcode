/*!
 * -------------------------------------------
 * Copyright (c) 2020, Horizon Robotics, Inc.
 * All rights reserved.
 * \File     11.container-with-most-water.cpp
 * \Author   Yingmin Li
 * \Mail     yingmin.li@horizon.ai
 * \Version  1.0.0.0
 * \Date     2020/1/8
 * \Brief    implement of 11.container-with-most-water.cpp
 * \DO NOT MODIFY THIS COMMENT, \
 * \WHICH IS AUTO GENERATED BY EDITOR
 * -------------------------------------------
 */
/*!
 * @brief https://leetcode-cn.com/problems/container-with-most-water/
 * Time: O(n)
 * Space: O(1)
 */
#include "leetcode/leetcode.h"
namespace horizon {
namespace leetcode {
int maxArea(vector<int>& height) {
  int i = 0;
  int j = height.size() - 1;
  int area = 0;
  while (i < j) {
    if (height[i] <= height[j]) {
      if ((height[i] * (j - i)) > area) {
        area = height[i] * (j - i);
      }
      ++i;
    } else {
      if ((height[j] * (j - i)) > area) {
        area = height[j] * (j - i);
      }
      --j;
    }
  }
  return area;
}
}  // namespace leetcode
}  // namespace horizon
