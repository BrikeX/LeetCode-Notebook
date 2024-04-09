/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

class Solution {
 public:
  int maximalSquare(std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return 0;
    }
    const auto row_size = matrix.size();
    const auto col_size = matrix.front().size();
    int result = 0;
    // std::vector<std::vector<int>> dp_table(row_size,
    //                                        std::vector<int>(col_size, 0));
    // for (std::size_t i = 0U; i < row_size; ++i) {
    //   for (std::size_t j = 0U; j < col_size; ++j) {
    //     if ('0' == matrix[i][j]) {
    //       continue;
    //     }
    //     if (0U == i || 0U == j) {
    //       dp_table[i][j] = 1;
    //     } else {
    //       dp_table[i][j] =
    //           std::min(dp_table[i - 1][j - 1],
    //                    std::min(dp_table[i][j - 1], dp_table[i - 1][j])) +
    //           1;
    //     }
    //     result = std::max(result, dp_table[i][j]);
    //   }
    // }
    std::vector<std::vector<int>> dp_table(2, std::vector<int>(col_size, 0));
    for (std::size_t j = 0U; j < col_size; ++j) {
      dp_table[0][j] = '0' == matrix[0][j] ? 0 : 1;
      if (!result && 1 == dp_table[0][j]) {
        result = 1;
      }
    }
    for (std::size_t i = 1U; i < row_size; ++i) {
      for (std::size_t j = 0U; j < col_size; ++j) {
        if ('0' == matrix[i][j]) {
          dp_table[1][j] = 0;
          continue;
        }
        if (0U == j) {
          dp_table[1][j] = 1;
        } else {
          dp_table[1][j] =
              std::min(dp_table[0][j - 1],
                       std::min(dp_table[1][j - 1], dp_table[0][j])) +
              1;
        }
        result = std::max(result, dp_table[1][j]);
      }
      std::swap(dp_table[0], dp_table[1]);
    }
    return result * result;
  }
};
// @lc code=end
