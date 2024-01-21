/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::map<int, int> num2index_map;
    const int nums_size = static_cast<int>(nums.size());

    for (int i = 0; i != nums_size; ++i) {
      const int n = nums[i];
      const auto it = num2index_map.find(target - n);
      if (num2index_map.cend() == it) {
        num2index_map.emplace(n, i);
      } else {
        return {i, it->second};
      }
    }

    return {};
  }
};
// @lc code=end
