/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
// #include <vector>

class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 0) {
      return 0;
    } else if (1 == n) {
      return 1;
    } else if (2 == n) {
      return 2;
    }
    const int dp_size = n + 1;
    // std::vector<int> dp_vec(dp_size, 1);
    // for (int i = 2; i < dp_size; ++i) {
    //   dp_vec[i] = dp_vec[i - 1] + dp_vec[i - 2];
    // }
    // return dp_vec.back();
    int f0 = 1;
    int f1 = 1;
    int dp = 0;
    for (int i = 2; i < dp_size; ++i) {
      dp = f0 + f1;
      f0 = f1;
      f1 = dp;
    }
    return dp;
  }
};
// @lc code=end
