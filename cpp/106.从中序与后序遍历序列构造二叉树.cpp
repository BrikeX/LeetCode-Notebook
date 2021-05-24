/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 递归算法
        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, int inorder_start, int inorder_end,
                    vector<int>& postorder, int postorder_start, int postorder_end)
    {
        if (inorder_start > inorder_end)
        {
            return nullptr;
        }

        int root_value = postorder[postorder_end];

        int root_index_inorder = find(inorder.begin() + inorder_start, inorder.begin() + inorder_end + 1, root_value) - inorder.begin();

        int left_size = root_index_inorder - inorder_start;
        
        TreeNode* root = new TreeNode(root_value);

        root->left = build(inorder, inorder_start, root_index_inorder - 1,
                           postorder, postorder_start, postorder_start + left_size - 1);
        
        root->right = build(inorder, root_index_inorder + 1, inorder_end,
                            postorder, postorder_start + left_size, postorder_end - 1);

        return root;
    }
};
// @lc code=end

