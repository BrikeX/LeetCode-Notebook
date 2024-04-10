/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
#include <cstddef>
#include <vector>

class NumMatrix {
 public:
  NumMatrix(std::vector<std::vector<int>>& matrix) {
    const auto row_size = matrix.size();
    const auto col_size = matrix.front().size();
    sum_table_.resize(row_size + 1, std::vector<int>(col_size + 1, 0));
    for (std::size_t i = 0U; i < row_size; ++i) {
      for (std::size_t j = 0U; j < col_size; ++j) {
        sum_table_[i + 1][j + 1] = sum_table_[i][j + 1] + sum_table_[i + 1][j] -
                                   sum_table_[i][j] + matrix[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum_table_[row2 + 1][col2 + 1] - sum_table_[row2 + 1][col1] -
           sum_table_[row1][col2 + 1] + sum_table_[row1][col1];
  }

 private:
  std::vector<std::vector<int>> sum_table_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
