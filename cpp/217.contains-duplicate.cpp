/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <cstddef>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    if (nums.empty()) {
      return false;
    } else if (1U == nums.size()) {
      return false;
    } else if (2U == nums.size()) {
      return *nums.cbegin() == *nums.crbegin();
    }
    std::unordered_set<int> num_set = {nums.front()};
    num_set.reserve(nums.size());
    for (std::size_t i = 1U; i < nums.size(); ++i) {
      if (num_set.cend() != num_set.find(nums[i])) {
        return true;
      }
      num_set.emplace(nums[i]);
    }
    return false;
  }
};
// @lc code=end
