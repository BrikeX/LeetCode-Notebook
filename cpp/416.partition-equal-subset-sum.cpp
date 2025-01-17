/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <algorithm>
#include <deque>
#include <vector>

class Solution {
 public:
  bool canPartition(std::vector<int>& nums) {
    if (nums.size() < 2U) {
      return false;
    }
    int sum = 0;
    int num_max = 0;
    for (const auto num : nums) {
      sum += num;
      num_max = std::max(num_max, num);
    }
    if (sum & 1) {
      return false;
    }
    sum /= 2;
    if (num_max > sum) {
      return false;
    }
    std::deque<bool> dp_vec(sum + 1, false);
    dp_vec[0] = true;

    for (const auto num : nums) {
      for (int v = sum; v >= num; --v) {
        dp_vec[v] |= dp_vec[v - num];

        if (dp_vec[sum]) {
          return true;
        }
      }
    }
    return dp_vec[sum];
  }
};
// @lc code=end
