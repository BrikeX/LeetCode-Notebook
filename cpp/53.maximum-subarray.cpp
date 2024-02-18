/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    if (1u == nums.size()) {
      return nums.front();
    }
    // std::vector<int> sub_sum(nums.size());
    // sub_sum[0] = nums[0];
    // int sub_sum_max = sub_sum[0];
    // for (std::size_t i = 1u; i < nums.size(); ++i) {
    //   sub_sum[i] = std::max(nums[i], sub_sum[i - 1] + nums[i]);
    //   sub_sum_max = std::max(sub_sum_max, sub_sum[i]);
    // }
    int f0 = nums[0];
    int f1 = 0;
    int sub_sum_max = f0;
    for (std::size_t i = 1u; i < nums.size(); ++i) {
      f1 = std::max(nums[i], f0 + nums[i]);
      sub_sum_max = std::max(sub_sum_max, f1);
      f0 = f1;
    }
    return sub_sum_max;
  }
};
// @lc code=end
