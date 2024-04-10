/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <cstddef>
#include <vector>

class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix.front().empty()) {
      return false;
    }
    const int row_size = matrix.size();
    const int col_size = matrix.front().size();
    if (1 == row_size && 1 == col_size) {
      return target == matrix.front().front();
    }
    int i = row_size - 1;
    int j = 0;
    while (i >= 0 && j < col_size) {
      if (target < matrix[i][j]) {
        --i;
      } else if (target > matrix[i][j]) {
        ++j;
      } else {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
