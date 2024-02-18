/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

class Solution {
 public:
  int minPathSum(std::vector<std::vector<int>> &grid) {
    if (grid.empty()) {
      return 0;
    }
    const auto row_size = grid.size();
    const auto col_size = grid.front().size();
    if (1u == row_size && 1u == col_size) {
      return grid[0][0];
    }
    // std::vector<std::vector<int>> dp_table(row_size,
    //                                        std::vector<int>(col_size));
    // dp_table[0][0] = grid[0][0];
    // for (std::size_t j = 1u; j < col_size; ++j) {
    //   dp_table[0][j] = dp_table[0][j - 1] + grid[0][j];
    // }
    // for (std::size_t i = 1u; i < row_size; ++i) {
    //   for (std::size_t j = 0u; j < col_size; ++j) {
    //     if (0u == j) {
    //       dp_table[i][j] = dp_table[i - 1][j] + grid[i][j];
    //     } else {
    //       dp_table[i][j] =
    //           std::min(dp_table[i][j - 1], dp_table[i - 1][j]) + grid[i][j];
    //     }
    //   }
    // }
    // return dp_table.back().back();
    std::vector<int> dp0_vec(col_size);
    dp0_vec[0] = grid[0][0];
    for (std::size_t j = 1u; j < col_size; ++j) {
      dp0_vec[j] = dp0_vec[j - 1] + grid[0][j];
    }
    if (1u == row_size) {
      return dp0_vec.back();
    }
    std::vector<int> dp1_vec(col_size);
    for (std::size_t i = 1u; i < row_size; ++i) {
      for (std::size_t j = 0u; j < col_size; ++j) {
        if (0u == j) {
          dp1_vec[j] = dp0_vec[j] + grid[i][j];
        } else {
          dp1_vec[j] = std::min(dp1_vec[j - 1], dp0_vec[j]) + grid[i][j];
        }
      }
      if (i + 1 < row_size) {
        std::swap(dp0_vec, dp1_vec);
      }
    }
    return dp1_vec.back();
  }
};
// @lc code=end
