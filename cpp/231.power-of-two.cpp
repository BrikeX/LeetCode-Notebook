/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    int count = 0;
    while (n) {
      if (n & 1) {
        ++count;
      }
      if (count > 1) {
        return false;
      }
      n >>= 1;
    }
    return 0 == count ? false : true;
  }
};
// @lc code=end
