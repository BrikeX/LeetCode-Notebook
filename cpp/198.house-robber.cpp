/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    std::vector<std::vector<int>> dp_table(nums.size(), std::vector<int>(2, 0));
    for (std::size_t i = 0U; i < nums.size(); ++i) {
      if (0U == i) {
        dp_table[i][1] = nums[i];
        continue;
      }
      dp_table[i][0] = std::max(dp_table[i - 1][0], dp_table[i - 1][1]);
      dp_table[i][1] = nums[i] + dp_table[i - 1][0];
    }
    return std::max(dp_table.back()[0], dp_table.back()[1]);
  }
};
// @lc code=end
