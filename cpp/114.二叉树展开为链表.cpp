/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        // 递归算法
        if (!root)
        {
            return;
        }
        
        flatten(root->left);

        flatten(root->right);

        TreeNode* left = root->left;

        TreeNode* right = root->right;

        root->left = nullptr;

        root->right = left;

        TreeNode* node_tmp = root;

        while (node_tmp->right)
        {
            node_tmp = node_tmp->right;
        }
        
        node_tmp->right = right;
    }
};
// @lc code=end

