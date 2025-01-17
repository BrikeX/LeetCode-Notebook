/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

class Solution {
 public:
  int minDistance(std::string word1, std::string word2) {
    std::vector<std::vector<int>> dp_table(
        word1.size() + 1, std::vector<int>(word2.size() + 1, 0));

    for (std::size_t i = 1; i < dp_table.size(); ++i) {
      dp_table[i][0] = i;
    }
    for (std::size_t j = 1; j < dp_table[0].size(); ++j) {
      dp_table[0][j] = j;
    }
    for (std::size_t i = 1; i < dp_table.size(); ++i) {
      for (std::size_t j = 1; j < dp_table[i].size(); ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp_table[i][j] = dp_table[i - 1][j - 1];
        } else {
          dp_table[i][j] =
              std::min(std::min(dp_table[i - 1][j] + 1, dp_table[i][j - 1] + 1),
                       dp_table[i - 1][j - 1] + 1);
        }
      }
    }
    return dp_table.back().back();
  }
};
// @lc code=end
