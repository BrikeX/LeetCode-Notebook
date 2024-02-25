/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <limits>

class Solution {
 public:
  int reverse(int x) {
    int rev = 0;
    int digit = 0;
    while (x != 0) {
      if (rev < kLowerLimit || rev > kUpperLimit) {
        return 0;
      }
      digit = x % 10;
      x /= 10;
      rev = rev * 10 + digit;
    }
    return rev;
  }

 private:
  static constexpr int kLowerLimit = std::numeric_limits<int>::lowest() / 10;
  static constexpr int kUpperLimit = std::numeric_limits<int>::max() / 10;
};
// @lc code=end
