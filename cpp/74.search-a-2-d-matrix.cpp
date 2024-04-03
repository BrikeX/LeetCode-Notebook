/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    auto row_begin = matrix.begin();
    auto row_end = matrix.end();
    auto row_mid = row_begin + (row_end - row_begin) / 2;
    while (row_end != row_mid) {
      if (target < *row_mid->begin()) {
        row_end = row_mid;
      } else {
        row_begin = row_mid + 1;
      }
      row_mid = row_begin + (row_end - row_begin) / 2;
    }
    if (matrix.begin() == row_mid) {
      return false;
    }
    const auto row_it = row_mid - 1;
    auto col_begin = row_it->begin();
    auto col_end = row_it->end();
    auto col_mid = col_begin + (col_end - col_begin) / 2;
    while (col_end != col_mid && *col_mid != target) {
      if (target < *col_mid) {
        col_end = col_mid;
      } else {
        col_begin = col_mid + 1;
      }
      col_mid = col_begin + (col_end - col_begin) / 2;
    }
    if (row_it->end() == col_mid || *col_mid != target) {
      return false;
    }
    return true;
  }
};
// @lc code=end
