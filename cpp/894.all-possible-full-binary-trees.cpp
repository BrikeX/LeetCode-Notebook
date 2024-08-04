/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 */

// @lc code=start
#include <vector>

//  Definition for a binary tree node.
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
 public:
  std::vector<TreeNode *> allPossibleFBT(int n) { return DivideAndConquer(n); }

 private:
  std::vector<TreeNode *> DivideAndConquer(const int n);
};

std::vector<TreeNode *> Solution::DivideAndConquer(const int n) {
  std::vector<TreeNode *> result;

  if (0 == n % 2) {
    return result;
  }
  if (1 == n) {
    result.emplace_back(new TreeNode(0));
    return result;
  }
  for (int i = 1; i < n; i += 2) {
    const auto left_results = DivideAndConquer(i);
    const auto right_results = DivideAndConquer(n - 1 - i);
    for (const auto left_tree : left_results) {
      for (const auto right_tree : right_results) {
        auto root = new TreeNode(0, left_tree, right_tree);
        result.emplace_back(root);
      }
    }
  }
  return result;
}
// @lc code=end
