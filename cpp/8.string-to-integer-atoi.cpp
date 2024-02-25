/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <cstddef>
#include <limits>
#include <string>

class Solution {
 public:
  int myAtoi(std::string s) {
    if (s.empty()) {
      return 0;
    }
    int ures = 0;
    int sign = 1;
    std::size_t index = 0;
    while (s[index] == ' ') {
      ++index;
      if (s.size() == index) {
        return 0;
      }
    }
    if ('-' == s[index]) {
      sign = -1;
    }
    if ('-' == s[index] || '+' == s[index]) {
      ++index;
    }
    for (auto i = index; i < s.size(); ++i) {
      if (s[i] < '0' || s[i] > '9') {
        break;
      }
      if (ures > kUpperLimit || (kUpperLimit == ures && s[i] > '7')) {
        return sign > 0 ? std::numeric_limits<int>::max()
                        : std::numeric_limits<int>::lowest();
      }
      ures = ures * 10 + (s[i] - '0');
    }
    if (sign < 0) {
      return sign * ures;
    }
    return ures;
  }

 private:
  static constexpr int kUpperLimit = std::numeric_limits<int>::max() / 10;
};
// @lc code=end
