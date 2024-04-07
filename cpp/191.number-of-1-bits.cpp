/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
 public:
  int hammingWeight(int n) {
    int result = 0;
    while (n) {
      if (n & 1) {
        ++result;
      }
      n >>= 1;
    }
    return result;
  }
};
// @lc code=end
