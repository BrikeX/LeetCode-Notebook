/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (1U == strs.size()) {
      return strs.front();
    }
    std::sort(strs.begin(), strs.end());
    int idx = 0;
    for (; idx < strs.cbegin()->size(); ++idx) {
      if (strs.cbegin()->at(idx) != strs.crbegin()->at(idx)) {
        break;
      }
    }
    return strs.cbegin()->substr(0, idx);
  }
};
// @lc code=end
