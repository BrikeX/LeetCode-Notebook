/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 迭代算法
        if (!root)
        {
            return nullptr;
        }
        
        if (root->val == key)
        {
            if (!root->left)
            {
                return root->right;
            }
            
            if (!root->right)
            {
                return root->left;
            }

            TreeNode* node_min = getMinNode(root->right);

            root->val = node_min->val;

            root->right = deleteNode(root->right, node_min->val);
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        
        return root;
    }

    TreeNode* getMinNode(TreeNode* root)
    {
        while (root->left)
        {
            root = root->left;
        }
        
        return root;
    }
};
// @lc code=end

