/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <cstddef>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    if (nums.empty()) {
      return {{}};
    } else if (1U == nums.size()) {
      return {{}, {nums[0]}};
    }
    subset_.reserve(nums.size());
    result_.reserve(nums.size() * nums.size());
    DFS(nums, 0U);

    return result_;
  }

 private:
  void DFS(const std::vector<int> &nums, const std::size_t start_index);

 private:
  std::vector<std::vector<int>> result_;
  std::vector<int> subset_;
};

void Solution::DFS(const std::vector<int> &nums,
                   const std::size_t start_index) {
  if (nums.size() == start_index) {
    result_.emplace_back(subset_);
    return;
  }
  subset_.emplace_back(nums[start_index]);
  DFS(nums, start_index + 1);
  subset_.pop_back();
  DFS(nums, start_index + 1);
}
// @lc code=end
