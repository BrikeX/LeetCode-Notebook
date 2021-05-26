/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
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
    int sum_max = 0;

    int maxSumBST(TreeNode* root) {
        // 递归算法
        traverse(root);

        return sum_max;
    }

    vector<int> traverse(TreeNode* root)
    {
        /*
        返回值定义：
        [0]: 以 root 为根的二叉树是否为 BST，1 是，0 不是
        [1]: 以 root 为根的二叉树中节点最小值
        [2]: 以 root 为根的二叉树中节点最大值
        [3]: 以 root 为根的二叉树中节点值之和
        */
        if (!root)
        {
            return {1, INT_MAX, INT_MIN, 0};
        }
        
        vector<int> left = traverse(root->left);

        vector<int> right = traverse(root->right);

        vector<int> result(4);

        if (left[0] && right[0] && root->val > left[2] && root->val < right[1])
        {
            result[0] = 1;

            result[1] = min(root->val, left[1]);

            result[2] = max(root->val, right[2]);

            result[3] = left[3] + right[3] + root->val;

            sum_max = max(sum_max, result[3]);
        }
        else
        {
            result[0] = 0;
        }
        
        return result;
    }
};
// @lc code=end

