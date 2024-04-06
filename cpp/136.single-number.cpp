/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  int singleNumber(std::vector<int> &nums) {
    if (1U == nums.size()) {
      return nums.front();
    }
    std::unordered_map<int, int> num_map;
    num_map.reserve(nums.size());
    for (const int num : nums) {
      ++num_map[num];
    }
    return std::find_if(num_map.cbegin(), num_map.cend(),
                        [](const std::pair<int, int> &num_pair) {
                          return 1 == num_pair.second;
                        })
        ->first;
  }
};
// @lc code=end
