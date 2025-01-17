/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
#include <cstddef>
#include <string>
#include <vector>

class Solution {
 public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector<std::vector<int>> dp_table(
        text1.size() + 1, std::vector<int>(text2.size() + 1, 0));

    for (std::size_t i = 1U; i != dp_table.size(); ++i) {
      for (std::size_t j = 1U; j != dp_table[i].size(); ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp_table[i][j] = dp_table[i - 1][j - 1] + 1;
        } else {
          dp_table[i][j] = std::max(dp_table[i][j - 1], dp_table[i - 1][j]);
        }
      }
    }
    return dp_table.back().back();
  }
};
// @lc code=end
