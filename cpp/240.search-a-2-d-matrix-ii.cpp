/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <iterator>
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
    auto row_beg = matrix.begin();
    auto row_end = matrix.end();
    auto row_mid = row_beg + (row_end - row_beg) / 2;
    while (row_end != row_mid) {
      if (target == row_mid->front()) {
        return true;
      } else if (target < row_mid->front()) {
        row_end = row_mid;
      } else {
        row_beg = row_mid + 1;
      }
      row_mid = row_beg + (row_end - row_beg) / 2;
    }
    if (matrix.begin() == row_mid) {
      return false;
    }
    int i = std::distance(matrix.begin(), row_mid - 1);
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
