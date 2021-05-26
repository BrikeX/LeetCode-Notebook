/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int n) {
        // DP
        if (n == 1)
        {
            vector<TreeNode*> result(1);
            
            result.front() = new TreeNode(1);
            
            return result;
        }
        
        return buildTree(1, n);
    }

    vector<TreeNode*> buildTree(int start, int end)
    {
        vector<TreeNode*> result;

        if (start > end)
        {
            result.push_back(nullptr);

            return result;
        }
        
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*> left = buildTree(start, i - 1);

            vector<TreeNode*> right = buildTree(i + 1, end);

            for (TreeNode* node_left : left)
            {
                for (TreeNode* node_right : right)
                {
                    TreeNode* root = new TreeNode(i);

                    root->left = node_left;

                    root->right = node_right;

                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
};
// @lc code=end

