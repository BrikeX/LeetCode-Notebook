/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  bool canJump(std::vector<int> &nums) {
    if (nums.size() <= 1U) {
      return true;
    }
    int rightmost = 0;
    const int size = static_cast<int>(nums.size());
    for (int i = 0; i + 1 < size; ++i) {
      if (i > rightmost) {
        break;
      }
      rightmost = std::max(rightmost, nums[i] + i);
      if (rightmost + 1 >= size) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
