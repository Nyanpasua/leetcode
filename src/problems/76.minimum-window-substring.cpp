/*!
 * -------------------------------------------
 * Copyright (c) 2020, Horizon Robotics, Inc.
 * All rights reserved.
 * \File     76.minimum-window-substring.cpp
 * \Author   Yingmin Li
 * \Mail     yingmin.li@horizon.ai
 * \Version  1.0.0.0
 * \Date     2020/1/2
 * \Brief    implement of 76.minimum-window-substring.cpp
 * \DO NOT MODIFY THIS COMMENT, \
 * \WHICH IS AUTO GENERATED BY EDITOR
 * -------------------------------------------
 */
/*!
 * @brief Given a string S and a string T, find the minimum window in S which
 * will contain all the characters in T in complexity O(n).
 * https://leetcode.com/problems/minimum-window-substring/
 */

#include <iostream>
#include <string>

#include "leetcode/leetcode.h"
namespace horizon {
namespace leetcode {
const int ASCII_SIZE = 256;
bool isMinimumWindowSubstr(const int* counter, const int* table) {
  for (int i = 0; i < ASCII_SIZE; ++i) {
    if (table[i] != 0 && table[i] > counter[i]) {
      return false;
    }
  }
  return true;
}
bool hasCharInTable(const char ch, const int* table) { return table[ch] != 0; }
string minWindow(string s, string t) {
  int i = 0, j = 0;  // [i, j)
  int table[ASCII_SIZE] = {};
  int counter[ASCII_SIZE] = {};
  int min_str_size = 0;
  std::string min_window;
  for (auto& t0 : t) {
    ++table[t0];
  }
  while (j <= s.size()) {
    counter[s[j++]]++;
    if (!hasCharInTable(s[i], table)) {
      counter[s[i++]]--;
    }
    if (isMinimumWindowSubstr(counter, table)) {
      min_str_size = j - i;
      min_window = std::string(s.begin() + i, s.begin() + j);
      break;
    }
  }
  while (j <= s.size()) {
    int idx = j;
    counter[s[j++]]++;
    if (s[idx] != s[i]) {
      continue;
    } else {
      while (isMinimumWindowSubstr(counter, table)) {
        if (hasCharInTable(s[i], table)) {
          if (min_str_size > j - i) {
            min_str_size = j - i;
            min_window = std::string(s.begin() + i, s.begin() + j);
          }
        }
        counter[s[i++]]--;
      }
      --i;
    }
  }
  return min_window;
}
}  // namespace leetcode
}  // namespace horizon
