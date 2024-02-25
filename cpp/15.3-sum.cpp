/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;

    if (nums.size() < 3U) {
      return result;
    } else if (3U == nums.size()) {
      if (0 == nums[0] + nums[1] + nums[2]) {
        result.push_back({nums[0], nums[1], nums[2]});
      }
      return result;
    }
    std::sort(nums.begin(), nums.end());
    for (std::size_t i = 0; i < nums.size() - 2; ++i) {
      if (i > 0U && nums[i] == nums[i - 1]) {
        continue;
      }
      if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
        break;
      }
      if (nums[i] + *(nums.rbegin() + 1) + nums.back() < 0) {
        continue;
      }
      auto j = i + 1;
      auto k = nums.size() - 1;
      int sum = 0;
      while (j < k) {
        sum = nums[i] + nums[j] + nums[k];
        if (sum < 0) {
          ++j;
        } else if (sum > 0) {
          --k;
        } else {
          result.push_back({nums[i], nums[j], nums[k]});
          for (++j; j < k && nums[j] == nums[j - 1]; ++j) {
          }
          for (--k; k > j && nums[k] == nums[k + 1]; --k) {
          }
        }
      }
    }
    return result;
  }
};
// @lc code=end
