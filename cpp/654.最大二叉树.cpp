/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // 递归算法
        return buildBinaryTree(nums, 0, nums.size() - 1);
    }

    TreeNode* buildBinaryTree(vector<int>& nums, int begin, int end)
    {
        if (begin > end)
        {
            return nullptr;
        }
        
        auto it = max_element(nums.begin() + begin, nums.begin() + end + 1);

        TreeNode* root = new TreeNode(*it);

        root->left = buildBinaryTree(nums, begin, it - nums.begin() - 1);

        root->right = buildBinaryTree(nums, it - nums.begin() + 1, end);

        return root;
    }
};
// @lc code=end

