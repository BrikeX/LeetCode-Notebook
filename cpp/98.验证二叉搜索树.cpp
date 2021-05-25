/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 递归算法
        return valid(root, nullptr, nullptr);
    }

    bool valid(TreeNode* root, TreeNode* tree_min, TreeNode* tree_max)
    {
        if (!root)
        {
            return true;
        }
        
        if (tree_min && root->val <= tree_min->val)
        {
            return false;
        }
        
        if (tree_max && root->val >= tree_max->val)
        {
            return false;
        }
        
        return valid(root->left, tree_min, root) && valid(root->right, root, tree_max);
    }
};
// @lc code=end

