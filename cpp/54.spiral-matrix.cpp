/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    if (matrix.empty()) {
      return {};
    }
    int left_size = matrix.size() * matrix.front().size();
    if (0 == left_size) {
      return {};
    } else if (1 == left_size) {
      return {matrix.front().front()};
    }
    std::vector<int> result;
    result.reserve(left_size);

    int left = 0;
    int top = 0;
    int right = matrix.front().size() - 1;
    int bottom = matrix.size() - 1;
    while (left_size > 0) {
      for (int i = left; i <= right && left_size > 0; ++i) {
        result.emplace_back(matrix[top][i]);
        --left_size;
      }
      ++top;
      for (int i = top; i <= bottom && left_size > 0; ++i) {
        result.emplace_back(matrix[i][right]);
        --left_size;
      }
      --right;
      for (int i = right; i >= left && left_size > 0; --i) {
        result.emplace_back(matrix[bottom][i]);
        --left_size;
      }
      --bottom;
      for (int i = bottom; i >= top && left_size > 0; --i) {
        result.emplace_back(matrix[i][left]);
        --left_size;
      }
      ++left;
    }
    return result;
  }
};
// @lc code=end
