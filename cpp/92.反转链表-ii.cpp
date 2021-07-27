/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 递归算法
        if (left == 1)
        {
            return reverse(head, right);
        }

        head->next = reverseBetween(head->next, left - 1, right - 1);

        return head;
    }

private:
    ListNode* successor = nullptr;

    ListNode* reverse(ListNode* head, int right)
    {
        if (right == 1)
        {
            successor = head->next;

            return head;
        }
        
        ListNode* last = reverse(head->next, right - 1);

        head->next->next = head;

        head->next = successor;

        return last;
    }
};
// @lc code=end

