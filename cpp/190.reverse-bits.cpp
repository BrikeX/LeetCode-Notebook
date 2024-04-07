/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
#include <cstdint>

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0U;
    for (int i = 0; i < 32 && n > 0U; ++i) {
      result |= (n & 1U) << (31 - i);
      n >>= 1;
    }
    return result;
  }
};
// @lc code=end
