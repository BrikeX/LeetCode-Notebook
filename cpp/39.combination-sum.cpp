/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                               int target) {
    DFS(candidates, 0, target);
    return result_;
  }

 private:
  void DFS(const std::vector<int>& candidates, const int index,
           const int target);

 private:
  int sum_ = 0;
  std::vector<int> digits_;
  std::vector<std::vector<int>> result_;
};

void Solution::DFS(const std::vector<int>& candidates, const int index,
                   const int target) {
  if (sum_ == target) {
    result_.push_back(digits_);
    return;
  }
  if (sum_ > target) {
    return;
  }
  if (index < 0 || index >= candidates.size()) {
    return;
  }
  for (int i = index; i < candidates.size(); ++i) {
    digits_.push_back(candidates[i]);
    sum_ += candidates[i];
    DFS(candidates, i, target);
    digits_.pop_back();
    sum_ -= candidates[i];
  }
}
// @lc code=end
