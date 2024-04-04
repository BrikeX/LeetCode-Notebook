/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

// @lc code=start
#include <cstddef>
#include <vector>

// Definition for a binary tree node.
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
  void flatten(TreeNode *root) {
    if (!root) {
      return;
    }
    PreOrderTraversal(root);
    for (std::size_t i = 0U; i + 1U < node_vec_.size(); ++i) {
      auto curr_node = node_vec_[i];
      auto next_node = node_vec_[i + 1U];
      curr_node->left = nullptr;
      curr_node->right = next_node;
    }
  }

 private:
  void PreOrderTraversal(TreeNode *const root);

 private:
  std::vector<TreeNode *> node_vec_;
};

void Solution::PreOrderTraversal(TreeNode *const root) {
  if (!root) {
    return;
  }
  node_vec_.emplace_back(root);
  PreOrderTraversal(root->left);
  PreOrderTraversal(root->right);
}
// @lc code=end
