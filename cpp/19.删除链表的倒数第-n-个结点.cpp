/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 双指针算法
        ListNode *slow = head, *fast = head;

        while (n-- > 0)
        {
            fast = fast->next;
        }
        
        if (!fast)
        {
            return head->next;
        }
        
        while (fast && fast->next)
        {
            fast = fast->next;

            slow = slow->next;
        }
        
        slow->next = slow->next->next;

        return head;
    }
};
// @lc code=end

