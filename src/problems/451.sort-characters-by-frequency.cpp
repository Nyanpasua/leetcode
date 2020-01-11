/*!
 * -------------------------------------------
 * Copyright (c) 2020, Horizon Robotics, Inc.
 * All rights reserved.
 * \File     451.sort-characters-by-frequency.cpp
 * \Author   Yingmin Li
 * \Mail     yingmin.li@horizon.ai
 * \Version  1.0.0.0
 * \Date     2020/1/10
 * \Brief    implement of 451.sort-characters-by-frequency.cpp
 * \DO NOT MODIFY THIS COMMENT, \
 * \WHICH IS AUTO GENERATED BY EDITOR
 * -------------------------------------------
 */
/*!
 * @brief https://leetcode-cn.com/problems/sort-characters-by-frequency/
 * Time: O(n) + klog(k), k = 256, n = s.size()
 * Space: O(n)+
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

#include "leetcode/leetcode.h"
namespace horizon {
namespace leetcode {

string frequencySort(string s) {
  std::unordered_map<char, int> counter;
  for (const auto& ch : s) {
    ++counter[ch];
  }
  std::vector<std::pair<char, int>> sort_arr;
  for (const auto& ch : counter) {
    sort_arr.emplace_back(ch);
  }
  std::sort(sort_arr.begin(), sort_arr.end(),
            [](std::pair<char, int>& p1, const std::pair<char, int>& p2) {
              return p1.second > p2.second;
            });
  std::string ret;
  for (const auto& ch : sort_arr) {
    ret += std::string(ch.second, ch.first);
  }
  return ret;
}
}  // namespace leetcode
}  // namespace horizon
