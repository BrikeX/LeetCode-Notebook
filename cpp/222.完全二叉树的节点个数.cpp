/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        // 递归算法
        TreeNode *left = root, *right = root;

        int depth_left = 0, depth_right = 0;

        while (left)
        {
            left = left->left;

            depth_left++;
        }
        
        while (right)
        {
            right = right->right;

            depth_right++;
        }
        
        if (depth_left == depth_right)
        {
            return pow(2, depth_left) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end

