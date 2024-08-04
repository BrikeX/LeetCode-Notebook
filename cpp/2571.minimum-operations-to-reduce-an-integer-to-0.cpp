/*
 * @lc app=leetcode id=2571 lang=cpp
 *
 * [2571] Minimum Operations to Reduce an Integer to 0
 */

// @lc code=start
#include <algorithm>

class Solution {
 public:
  int minOperations(int n) { return DFS(n); }

 private:
  int LowBit(const int n) { return n & (-n); }

  int DFS(const int n) {
    const int low_bit = LowBit(n);
    if (0 == n - low_bit) {
      return 1;
    }
    return std::min(DFS(n + low_bit), DFS(n - low_bit)) + 1;
  }
};
// @lc code=end
