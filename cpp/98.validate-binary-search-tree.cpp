/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
#include <limits>

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
  bool isValidBST(TreeNode *root) {
    if (!root) {
      return true;
    }
    return CheckBST(*root, std::numeric_limits<long long>::lowest(),
                    std::numeric_limits<long long>::max());
  }

 private:
  static bool CheckBST(const TreeNode &node, const long long &min,
                       const long long &max);
};

bool Solution::CheckBST(const TreeNode &node, const long long &min,
                        const long long &max) {
  if (node.val <= min || node.val >= max) {
    return false;
  }
  bool valid = true;
  if (node.left) {
    valid = CheckBST(*(node.left), min, node.val);
  }
  if (node.right && valid) {
    valid = CheckBST(*(node.right), node.val, max);
  }
  return valid;
}
// @lc code=end
