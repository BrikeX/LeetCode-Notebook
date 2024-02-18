/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */

// @lc code=start
#include <cstddef>
#include <queue>

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
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    if (!root->left && !root->right) {
      return 1;
    }
    int min_depth = 1;
    std::queue<TreeNode *> frontier;
    frontier.push(root);
    while (!frontier.empty()) {
      const auto queue_size = frontier.size();
      for (std::size_t i = 0; i < queue_size; ++i) {
        const auto node = frontier.front();
        frontier.pop();
        if (!node || (!node->left && !node->right)) {
          return min_depth;
        }
        if (node->left) {
          frontier.push(node->left);
        }
        if (node->right) {
          frontier.push(node->right);
        }
      }
      ++min_depth;
    }
    return min_depth;
  }
};
// @lc code=end
