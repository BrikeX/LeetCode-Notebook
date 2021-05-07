/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // 递归算法
        if (!root)
        {
            return nullptr;
        }
        
        connectTwoNode(root->left, root->right);

        return root;
    }

    void connectTwoNode(Node* left, Node* right)
    {
        if (!left || !right)
        {
            return;
        }

        left->next = right;

        connectTwoNode(left->left, left->right);

        connectTwoNode(right->left, right->right);
        
        connectTwoNode(left->right, right->left);
    }
};
// @lc code=end

