/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (0 == m || 0 == n) {
      return 0;
    }
    if (1 == m || 1 == n) {
      return 1;
    }
    // std::vector<std::vector<int>> dp_table(m, std::vector<int>(n));
    // for (int i = 0; i < m; ++i) {
    //   dp_table[i][0] = 1;
    // }
    // for (int j = 0; j < n; ++j) {
    //   dp_table[0][j] = 1;
    // }
    // for (int i = 1; i < m; ++i) {
    //   for (int j = 1; j < n; ++j) {
    //     dp_table[i][j] = dp_table[i - 1][j] + dp_table[i][j - 1];
    //   }
    // }
    // return dp_table.back().back();
    std::vector<int> dp_vec(n, 1);
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp_vec[j] += dp_vec[j - 1];
      }
    }
    return dp_vec.back();
  }
};
// @lc code=end
