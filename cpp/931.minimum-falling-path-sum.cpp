/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

class Solution {
 public:
  int minFallingPathSum(std::vector<std::vector<int>> &matrix) {
    if (matrix.empty()) {
      return 0;
    }
    // a nxn matrix
    const auto size = matrix.size();
    if (1u == size) {
      return matrix[0][0];
    }
    // std::vector<std::vector<int>> dp_table(size, std::vector<int>(size));
    // dp_table[0] = matrix[0];
    // for (std::size_t i = 1u; i < size; ++i) {
    //   for (std::size_t j = 0u; j < size; ++j) {
    //     if (0u == j) {
    //       dp_table[i][j] = matrix[i][j] +
    //                        std::min(dp_table[i - 1][j], dp_table[i - 1][j +
    //                        1]);
    //     } else if (size == j + 1u) {
    //       dp_table[i][j] = matrix[i][j] +
    //                        std::min(dp_table[i - 1][j], dp_table[i - 1][j -
    //                        1]);
    //     } else {
    //       dp_table[i][j] =
    //           matrix[i][j] +
    //           std::min(dp_table[i - 1][j - 1],
    //                    std::min(dp_table[i - 1][j], dp_table[i - 1][j + 1]));
    //     }
    //   }
    // }
    // return *std::min_element(dp_table.back().begin(), dp_table.back().end());
    std::vector<std::vector<int>> dp_table(2, std::vector<int>(size));
    dp_table[0] = matrix[0];
    for (std::size_t i = 1u; i < size; ++i) {
      for (std::size_t j = 0u; j < size; ++j) {
        if (0u == j) {
          dp_table[1][j] =
              matrix[i][j] + std::min(dp_table[0][j], dp_table[0][j + 1]);
        } else if (size == j + 1u) {
          dp_table[1][j] =
              matrix[i][j] + std::min(dp_table[0][j], dp_table[0][j - 1]);
        } else {
          dp_table[1][j] =
              matrix[i][j] +
              std::min(dp_table[0][j - 1],
                       std::min(dp_table[0][j], dp_table[0][j + 1]));
        }
      }
      if (i + 1u < size) {
        std::swap(dp_table[0], dp_table[1]);
      }
    }
    return *std::min_element(dp_table.back().begin(), dp_table.back().end());
  }
};
// @lc code=end
