/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int findShortestSubArray(std::vector<int>& nums) {
    std::unordered_map<int, std::vector<int>> num_umap;
    num_umap.reserve(nums.size());

    for (int i = 0; i < nums.size(); ++i) {
      if (num_umap.end() != num_umap.find(nums[i])) {
        ++num_umap[nums[i]][0];
        num_umap[nums[i]][2] = i;
      } else {
        num_umap[nums[i]] = {1, i, i};
      }
    }
    int count_max = 0;
    int len_min = 0;
    for (const auto& [num, memo] : num_umap) {
      if (count_max < memo[0]) {
        count_max = memo[0];
        len_min = memo[2] - memo[1] + 1;
      } else if (memo[0] == count_max) {
        len_min = std::min(len_min, memo[2] - memo[1] + 1);
      }
    }
    return len_min;
  }
};
// @lc code=end
