/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::map<int, int> num2index_map;

    for (int i = 0; i != nums.size(); ++i) {
      const auto it = num2index_map.find(target - nums[i]);
      if (num2index_map.cend() == it) {
        num2index_map.emplace(nums[i], i);
      } else {
        return {i, it->second};
      }
    }

    return {};
  }
};
// @lc code=end
