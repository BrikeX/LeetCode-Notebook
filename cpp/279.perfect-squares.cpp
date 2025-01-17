/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int numSquares(int n) {
    std::vector<int> dp_vec(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      int min_val = std::numeric_limits<int>::max();
      for (int j = 1; j * j <= i; ++j) {
        min_val = std::min(min_val, dp_vec[i - j * j]);
      }
      dp_vec[i] = min_val + 1;
    }
    return dp_vec.back();
  }
};
// @lc code=end
