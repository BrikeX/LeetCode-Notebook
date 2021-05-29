/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 双指针算法
        if (!head)
        {
            return nullptr;
        }
        
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;

            slow = slow->next;

            if (slow == fast)
            {
                break;
            }
        }
        
        if (!fast || !fast->next)
        {
            return nullptr;
        }
        
        slow = head;

        while (slow != fast)
        {
            slow = slow->next;

            fast = fast->next;
        }
        
        return slow;
    }
};
// @lc code=end

