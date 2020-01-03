/*!
 * -------------------------------------------
 * Copyright (c) 2019, Horizon Robotics, Inc.
 * All rights reserved.
 * \File     438.find-all-anagrams-in-a-string.cpp
 * \Author   Yingmin Li
 * \Mail     yingmin.li@horizon.ai
 * \Version  1.0.0.0
 * \Date     2019/12/31
 * \Brief    implement of 438.find-all-anagrams-in-a-string.cpp
 * \DO NOT MODIFY THIS COMMENT, \
 * \WHICH IS AUTO GENERATED BY EDITOR
 * -------------------------------------------
 */
/*!
 * @brief Given a string s and a non-empty string p, find all the start indices
 * of p's anagrams in s.
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/
 */

#include <iostream>
#include <string>
#include <unordered_map>

#include "leetcode/leetcode.h"
namespace horizon {
namespace leetcode {

bool FindSuccess(const std::string& sub,
                 const std::unordered_map<char, int>& p_map) {
  std::unordered_map<char, int> sub_map;
  for (auto& ch : sub) {
    sub_map[ch]++;
  }
  return p_map == sub_map;
}
vector<int> findAnagrams(string s, string p) {
  std::unordered_map<char, int> p_map;
  for (auto& ch : p) {
    p_map[ch]++;
  }
  size_t i = 0, j = 0;  // [i, j)
  std::vector<int> indexs = {};
  for (j = i + p.size(); j <= s.size(); ++i, j = i + p.size()) {
    if (FindSuccess(s.substr(i, p.size()), p_map)) {
      indexs.push_back(i);
    }
  }
  return indexs;
}
}  // namespace leetcode
}  // namespace horizon
