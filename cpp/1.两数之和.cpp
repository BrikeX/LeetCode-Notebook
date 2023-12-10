/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& nums, const int target) {
    // hash table
    std::unordered_map<int, int> hash_table;
    const int num_size = static_cast<int>(nums.size());

    for (int i = 0; i < num_size; ++i) {
      const auto it = hash_table.find(target - nums[i]);
      if (hash_table.cend() != it) {
        return {it->second, i};
      }
      hash_table[nums[i]] = i;
    }
    return {};

    // brute-force
    // std::vector<int> result(2);
    // for (std::size_t i = 0; i < nums.size() - 1; i++) {
    //   for (std::size_t j = i + 1; j < nums.size(); j++) {
    //     if (nums[i] + nums[j] == target) {
    //       result[0] = i;
    //       result[1] = j;
    //       return result;
    //     }
    //   }
    // }
    // result.clear();
    // return result;
  }
};
// @lc code=end
