/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    unordered_map<string, int> memo;

    vector<TreeNode*> result;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // 递归算法
        traverse(root);

        return result;
    }

    string traverse(TreeNode* root)
    {
        if (!root)
        {
            return "#";
        }
        
        string left = traverse(root->left);

        string right = traverse(root->right);

        string tree_sub = left + "," + right + "," + to_string(root->val);

        auto it = memo.find(tree_sub);

        if (it != memo.end())
        {
            if (it->second == 1)
            {
                result.push_back(root);
            }
        }
        
        memo[tree_sub]++;

        return tree_sub;
    }
};
// @lc code=end

