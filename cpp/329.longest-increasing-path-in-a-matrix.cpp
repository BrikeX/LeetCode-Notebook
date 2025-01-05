/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
 public:
  int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix.begin()->empty()) {
      return 0;
    }
    row_size_ = matrix.size();
    col_size_ = matrix.begin()->size();
    memo_.resize(row_size_, std::vector<int>(col_size_, 0));

    int length_max = 0;
    for (int i = 0; i < row_size_; ++i) {
      for (int j = 0; j < col_size_; ++j) {
        length_max = std::max(length_max, DFS(matrix, i, j));
      }
    }
    return length_max;
  }

 private:
  int DFS(const std::vector<std::vector<int>>& matrix, const int row,
          const int col);
  bool CheckInside(const int row, const int col) const;

 private:
  int row_size_ = 0;
  int col_size_ = 0;
  std::vector<std::vector<int>> memo_;
};

bool Solution::CheckInside(const int row, const int col) const {
  if (row < 0 || row >= row_size_) {
    return false;
  }
  if (col < 0 || col >= col_size_) {
    return false;
  }
  return true;
}

int Solution::DFS(const std::vector<std::vector<int>>& matrix, const int row,
                  const int col) {
  if (!CheckInside(row, col)) {
    return 0;
  }
  if (0 != memo_[row][col]) {
    return memo_[row][col];
  }
  ++memo_[row][col];

  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      if (0 == i && 0 == j) {
        continue;
      }
      if (2 == std::abs(i) + std::abs(j)) {
        continue;
      }
      const int new_row = row + i;
      const int new_col = col + j;
      if (!CheckInside(new_row, new_col)) {
        continue;
      }
      if (matrix[row][col] >= matrix[new_row][new_col]) {
        continue;
      }
      memo_[row][col] =
          std::max(memo_[row][col], DFS(matrix, new_row, new_col) + 1);
    }
  }
  return memo_[row][col];
}
// @lc code=end
