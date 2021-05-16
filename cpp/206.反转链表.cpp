/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        // 递归算法
        if (head == nullptr)
        {
            return nullptr;
        }
        
        if (head->next == nullptr)
        {
            return head;
        }
        
        ListNode* last = reverseList(head->next);

        head->next->next = head;

        head->next = nullptr;

        return last;
    }
};
// @lc code=end

