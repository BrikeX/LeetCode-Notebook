/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

class Solution {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    // transpose
    for (std::size_t i = 0U; i < matrix.size(); ++i) {
      for (std::size_t j = 0U; j <= i; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
    // reverse columns
    for (auto& row : matrix) {
      std::reverse(row.begin(), row.end());
    }
  }
};
// @lc code=end
