/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) {
    if (nums.size() <= 1U) {
      return;
    }
    auto slow_it = nums.begin();
    auto fast_it = nums.begin();

    while (nums.end() != fast_it && nums.end() != slow_it) {
      if (*fast_it) {
        if (fast_it != slow_it) {
          std::swap(*slow_it, *fast_it);
        }
        ++slow_it;
      }
      ++fast_it;
    }
  }
};
// @lc code=end
