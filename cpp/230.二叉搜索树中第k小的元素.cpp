/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int result;

    int rank;

    int kthSmallest(TreeNode* root, int k) {
        // BST 的中序遍历是升序的
        traverse(root, k);

        return result;
    }

    void traverse(TreeNode* root, int k)
    {
        if (!root)
        {
            return;
        }
        
        traverse(root->left, k);

        rank++;

        if (k == rank)
        {
            result = root->val;

            return;
        }
        
        traverse(root->right, k);
    }
};
// @lc code=end

