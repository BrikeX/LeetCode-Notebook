/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize_result;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // 前序遍历，超时
        // preorderSerialize(root);

        // 后序遍历
        // postorderSerialize(root);

        // 层级遍历
        hierarchySerialize(root);

        if (!serialize_result.empty())
        {
            serialize_result.pop_back();
        }
        
        return serialize_result;
    }

    void preorderSerialize(TreeNode* root)
    {
        if (!root)
        {
            serialize_result += "null";

            serialize_result += ",";
            
            return;
        }
        
        stringstream ss;

        ss << root->val;

        serialize_result += ss.str();
        
        serialize_result += ",";

        preorderSerialize(root->left);

        preorderSerialize(root->right);
    }

    void postorderSerialize(TreeNode* root)
    {
        if (!root)
        {
            serialize_result += "null";

            serialize_result += ",";
            
            return;
        }

        postorderSerialize(root->left);

        postorderSerialize(root->right);

        stringstream ss;

        ss << root->val;

        serialize_result += ss.str();
        
        serialize_result += ",";
    }

    void hierarchySerialize(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        
        queue<TreeNode*> q_node;

        q_node.push(root);

        TreeNode* node;

        stringstream ss;

        while (!q_node.empty())
        {
            node = q_node.front();

            q_node.pop();

            if (!node)
            {
                serialize_result += "null";

                serialize_result += ",";

                continue;
            }

            ss.clear();

            ss.str("");

            ss << node->val;

            serialize_result += ss.str();
            
            serialize_result += ",";

            q_node.push(node->left);

            q_node.push(node->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> data_str;
        
        char* cstr = new char [data.size() + 1];

        strcpy(cstr, data.c_str());

        char* cstr_split = strtok(cstr, ",");

        while (cstr_split != NULL)
        {
            data_str.push_back(cstr_split);

            cstr_split = strtok(NULL, ",");
        }
        
        // 前序遍历，超时
        // return preorderDeserialize(data_str);

        // 后序遍历
        // return postorderDeserialize(data_str);

        // 层级遍历
        return hierarchyDeserialize(data_str);
    }

    TreeNode* preorderDeserialize(vector<string>& data_str)
    {
        if (data_str.empty())
        {
            return nullptr;
        }
        
        stringstream ss;

        ss << data_str.front();

        data_str.erase(data_str.begin());

        if (ss.str() == "null")
        {
            return nullptr;
        }

        int node_value;

        ss >> node_value;

        TreeNode* root = new TreeNode(node_value);

        root->left = preorderDeserialize(data_str);
        
        root->right = preorderDeserialize(data_str);

        return root;
    }

    TreeNode* postorderDeserialize(vector<string>& data_str)
    {
        if (data_str.empty())
        {
            return nullptr;
        }
        
        stringstream ss;

        ss << data_str.back();

        data_str.pop_back();

        if (ss.str() == "null")
        {
            return nullptr;
        }

        int node_value;

        ss >> node_value;

        TreeNode* root = new TreeNode(node_value);

        root->right = postorderDeserialize(data_str);

        root->left = postorderDeserialize(data_str);

        return root;
    }

    TreeNode* hierarchyDeserialize(vector<string>& data_str)
    {
        if (data_str.empty())
        {
            return nullptr;
        }

        stringstream ss;

        ss << data_str.front();

        int node_value;

        ss >> node_value;

        TreeNode* root = new TreeNode(node_value);

        queue<TreeNode*> q_node;

        q_node.push(root);

        TreeNode* node;

        string left, right;

        for (size_t i = 1; i < data_str.size(); )
        {
            node = q_node.front();

            q_node.pop();

            left = data_str[i++];

            if (left != "null")
            {
                ss.clear();

                ss.str("");

                ss << left;

                ss >> node_value;

                node->left = new TreeNode(node_value);

                q_node.push(node->left);
            }
            else
            {
                node->left = nullptr;
            }
            
            right = data_str[i++];

            if (right != "null")
            {
                ss.clear();

                ss.str("");

                ss << right;

                ss >> node_value;

                node->right = new TreeNode(node_value);

                q_node.push(node->right);
            }
            else
            {
                node->right = nullptr;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

