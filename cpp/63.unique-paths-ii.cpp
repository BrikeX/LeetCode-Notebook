/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
    if (obstacleGrid.empty()) {
      return 0;
    }
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();
    if (0 == m || 0 == n) {
      return 0;
    }
    if (1 == obstacleGrid[0][0]) {
      return 0;
    }
    if (1 == m) {
      const auto it =
          std::find_if(obstacleGrid[0].cbegin(), obstacleGrid[0].cend(),
                       [](const int grid) { return 1 == grid; });
      if (obstacleGrid[0].cend() == it) {
        return 1;
      } else {
        return 0;
      }
    }
    if (1 == n) {
      const auto it = std::find_if(obstacleGrid.cbegin(), obstacleGrid.cend(),
                                   [](const std::vector<int> &row_vec) {
                                     return 1 == *row_vec.cbegin();
                                   });
      if (obstacleGrid.cend() == it) {
        return 1;
      } else {
        return 0;
      }
    }
    // std::vector<std::vector<int>> dp_table(m, std::vector<int>(n, 0));
    // dp_table[0][0] = 1;
    // for (int i = 1; i < m; ++i) {
    //   if (1 == obstacleGrid[i][0]) {
    //     break;
    //   }
    //   dp_table[i][0] = 1;
    // }
    // for (int j = 1; j < n; ++j) {
    //   if (1 == obstacleGrid[0][j]) {
    //     break;
    //   }
    //   dp_table[0][j] = 1;
    // }
    // for (int i = 1; i < m; ++i) {
    //   for (int j = 1; j < n; ++j) {
    //     if (1 == obstacleGrid[i][j]) {
    //       continue;
    //     }
    //     dp_table[i][j] = dp_table[i - 1][j] + dp_table[i][j - 1];
    //   }
    // }
    // return dp_table.back().back();
    std::vector<int> dp_vec(n, 0);
    for (int j = 0; j < n; ++j) {
      if (1 == obstacleGrid[0][j]) {
        break;
      }
      dp_vec[j] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (1 == obstacleGrid[i][j]) {
          dp_vec[j] = 0;
          continue;
        }
        if (0 == j) {
          continue;
        }
        dp_vec[j] += dp_vec[j - 1];
      }
    }
    return dp_vec.back();
  }
};
// @lc code=end
