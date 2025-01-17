/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> result = {{1}};
    if (1 >= numRows) {
      return std::move(result);
    }
    result.reserve(numRows);
    for (int i = 2; i <= numRows; ++i) {
      std::vector<int> row_vec(i, 1);
      for (int j = 0; j < row_vec.size(); ++j) {
        if (0 == j || row_vec.size() == j + 1) {
          continue;
        }
        row_vec[j] = result.back()[j] + result.back()[j - 1];
      }
      result.emplace_back(std::move(row_vec));
    }
    return std::move(result);
  }
};
// @lc code=end
