/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* left;

    bool isPalindrome(ListNode* head) {
        // 递归算法
        left = head;

        return traverse(head);
    }

    bool traverse(ListNode* right)
    {
        if (!right)
        {
            return true;
        }
        
        bool result = traverse(right->next);

        result = result && (right->val == left->val);

        left = left->next;

        return result;
    }
};
// @lc code=end

