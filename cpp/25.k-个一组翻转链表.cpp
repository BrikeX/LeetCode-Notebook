/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 递归算法
        if (k == 1)
        {
            return head;
        }
        
        if (!head)
        {
            return nullptr;
        }

        ListNode* left = head;
        
        ListNode* right = head;

        for (int i = 0; i < k; ++i)
        {
            if (!right)
            {
                return head;
            }
            
            right = right->next;
        }
        
        ListNode* new_head = reverseBetween(left, right);

        left->next = reverseKGroup(right, k);

        return new_head;
    }

private:
    ListNode* reverseBetween(ListNode* left, ListNode* right)
    {
        ListNode* pre = nullptr;

        ListNode* cur = left;

        ListNode* nxt;

        while (cur != right)
        {
            nxt = cur->next;

            cur->next = pre;

            pre = cur;

            cur = nxt;
        }
        
        return pre;
    }
};
// @lc code=end

