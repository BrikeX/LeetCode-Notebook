/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int subarraySum(std::vector<int>& nums, int k) {
    int result = 0;
    if (nums.empty()) {
      return result;
    }
    std::unordered_map<int, int> sum_map;
    sum_map[0] = 1;

    int pre_sum = 0;
    int target_sum = 0;
    for (const int num : nums) {
      pre_sum += num;
      target_sum = pre_sum - k;
      if (sum_map.cend() != sum_map.find(target_sum)) {
        result += sum_map.at(target_sum);
      }
      if (sum_map.cend() == sum_map.find(pre_sum)) {
        sum_map[pre_sum] = 1;
      } else {
        sum_map.at(pre_sum) += 1;
      }
    }
    return result;
  }
};
// @lc code=end
