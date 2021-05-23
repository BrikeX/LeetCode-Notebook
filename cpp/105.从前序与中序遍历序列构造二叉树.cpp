/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 递归算法
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int preorder_start, int preorder_end,
                    vector<int>& inorder, int inorder_start, int inorder_end)
    {
        if (preorder_start > preorder_end)
        {
            return nullptr;
        }
        
        int root_value = preorder[preorder_start];

        int root_index_inorder = find(inorder.begin() + inorder_start, inorder.begin() + inorder_end + 1, root_value) - inorder.begin();

        int left_size = root_index_inorder - inorder_start;

        TreeNode* root = new TreeNode(root_value);

        root->left = build(preorder, preorder_start + 1, preorder_start + left_size,
                           inorder, inorder_start, root_index_inorder - 1);

        root->right = build(preorder, preorder_start + left_size + 1, preorder_end,
                            inorder, root_index_inorder + 1, inorder_end);

        return root;
    }
};
// @lc code=end

