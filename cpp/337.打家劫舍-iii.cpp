/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    unordered_map<TreeNode*, int> memo;

    int rob(TreeNode* root) {
        // DP
        if (root == nullptr)
        {
            return 0;
        }
        
        auto it = memo.find(root);

        if (it != memo.end())
        {
            return it->second;
        }

        int do_rob = root->val + 
                     (root->left == nullptr ? 0 : rob(root->left->left) + rob(root->left->right)) + 
                     (root->right == nullptr ? 0 : rob(root->right->left) + rob(root->right->right));
        
        int not_rob = rob(root->left) + rob(root->right);

        int result = max(do_rob, not_rob);

        memo[root] = result;

        return result;
    }
};
// @lc code=end

