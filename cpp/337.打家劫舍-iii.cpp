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
    int rob(TreeNode* root) {
        // DP
        vector<int> result = dp(root);

        return max(result[0], result[1]);

        // // DP
        // if (root == nullptr)
        // {
        //     return 0;
        // }
        
        // auto it = memo.find(root);

        // if (it != memo.end())
        // {
        //     return it->second;
        // }

        // int do_rob = root->val + 
        //              (root->left == nullptr ? 0 : rob(root->left->left) + rob(root->left->right)) + 
        //              (root->right == nullptr ? 0 : rob(root->right->left) + rob(root->right->right));
        
        // int not_rob = rob(root->left) + rob(root->right);

        // int result = max(do_rob, not_rob);

        // memo[root] = result;

        // return result;
    }

private:
    // unordered_map<TreeNode*, int> memo;

    vector<int> dp(TreeNode* root)
    {
        if (!root)
        {
            return {0, 0};
        }
        
        vector<int> result(2);

        vector<int> left = dp(root->left);

        vector<int> right = dp(root->right);

        result[0] = max(left[0], left[1]) + max(right[0], right[1]);

        result[1] = root->val + left[0] + right[0];

        return result;
    }
};
// @lc code=end

