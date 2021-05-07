/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        // BFS
        if (root == nullptr)
        {
            return 0;
        }
        
        queue<TreeNode*> q_tree;

        q_tree.push(root);

        int depth = 1;

        TreeNode* node_tmp;

        int tree_size;

        while (!q_tree.empty())
        {
            tree_size = q_tree.size();

            for (size_t i = 0; i < tree_size; i++)
            {
                node_tmp = q_tree.front();

                q_tree.pop();

                if (node_tmp->left == nullptr && node_tmp->right == nullptr)
                {
                    return depth;
                }
                
                if (node_tmp->left != nullptr)
                {
                    q_tree.push(node_tmp->left);
                }
                
                if (node_tmp->right != nullptr)
                {
                    q_tree.push(node_tmp->right);
                }
            }

            depth++;
        }
        
        return depth;
    }
};
// @lc code=end

