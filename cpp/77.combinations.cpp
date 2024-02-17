/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combine(int n, int k) {
    DFS(1, n, k);
    return result_;
  }

 private:
  void DFS(const int i, const int n, const int k);

 private:
  std::vector<std::vector<int>> result_;
  std::vector<int> temp_;
};

void Solution::DFS(const int i, const int n, const int k) {
  if (temp_.size() + (n - i + 1) < k) {
    return;
  }
  if (temp_.size() == k) {
    result_.push_back(temp_);
    return;
  }
  // if (n + 1 == i) {
  //   return;
  // }
  temp_.push_back(i);
  DFS(i + 1, n, k);
  temp_.pop_back();
  DFS(i + 1, n, k);
}
// @lc code=end
