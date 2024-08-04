/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <string>

class Solution {
 public:
  int countBinarySubstrings(std::string s) {
    std::size_t index = 0U;
    const auto s_size = s.size();
    int curr_count = 0;
    int last_count = 0;
    int result = 0;

    while (index < s_size) {
      const char cval = s[index];
      curr_count = 0;
      while (index < s_size && cval == s[index]) {
        ++index;
        ++curr_count;
      }
      result += std::min(curr_count, last_count);
      last_count = curr_count;
    }
    return result;
  }
};
// @lc code=end
