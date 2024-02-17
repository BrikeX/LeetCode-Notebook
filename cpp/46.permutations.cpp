/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <cstddef>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    result_.clear();
    if (nums.empty()) {
      return result_;
    }
    if (1u == nums.size()) {
      result_.push_back(nums);
      return result_;
    }
    DFS(0u, &nums);
    return result_;
  }

 private:
  void DFS(const std::size_t start_index, std::vector<int> *const nums);

 private:
  std::vector<std::vector<int>> result_;
};

void Solution::DFS(const std::size_t start_index,
                   std::vector<int> *const nums) {
  if (!nums) {
    return;
  }
  if (start_index + 1u == nums->size()) {
    result_.push_back(*nums);
    return;
  }
  for (std::size_t i = start_index; i < nums->size(); ++i) {
    std::swap((*nums)[i], (*nums)[start_index]);
    DFS(start_index + 1u, nums);
    std::swap((*nums)[i], (*nums)[start_index]);
  }
}
// @lc code=end
