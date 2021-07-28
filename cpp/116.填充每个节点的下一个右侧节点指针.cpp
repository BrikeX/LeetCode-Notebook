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

private:
    void connectTwoNode(Node* node_left, Node* node_right)
    {
        if (!node_left || !node_right)
        {
            return;
        }
        
        node_left->next = node_right;

        connectTwoNode(node_left->left, node_left->right);

        connectTwoNode(node_right->left, node_right->right);

        connectTwoNode(node_left->right, node_right->left);
    }
};
// @lc code=end

