/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 把二叉搜索树转换为累加树
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
    int sum = 0;
    
    TreeNode* bstToGst(TreeNode* root) {
        // 与 538 相同
        // BST 先递归右侧再递归左侧为降序
        traverse(root);

        return root;
    }

    void traverse(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        
        traverse(root->right);

        sum += root->val;

        root->val = sum;

        traverse(root->left);
    }
};
// @lc code=end

