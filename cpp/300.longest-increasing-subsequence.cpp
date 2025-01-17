/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> dp_vec(nums.size(), 1);
    int result = dp_vec[0];

    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] <= nums[j]) {
          continue;
        }
        dp_vec[i] = std::max(dp_vec[i], dp_vec[j] + 1);
      }
      result = std::max(result, dp_vec[i]);
    }
    return result;
  }
};
// @lc code=end
