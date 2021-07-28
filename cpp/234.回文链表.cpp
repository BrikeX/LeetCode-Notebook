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
    bool isPalindrome(ListNode* head) {
        // 双指针算法
        ListNode* slow = head;
        
        ListNode* fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;

            fast = fast->next->next;
        }
        
        if (fast)
        {
            slow = slow->next;
        }
        
        ListNode* left = head;

        ListNode* right = reverseList(slow);

        while (right)
        {
            if (left->val != right->val)
            {
                return false;
            }
            
            left = left->next;

            right = right->next;
        }
        
        return true;
    }

private:
    ListNode* reverseList(ListNode* head)
    {
        // 迭代算法
        ListNode* pre = nullptr;

        ListNode* cur = head;

        ListNode* nxt;

        while (cur)
        {
            nxt = cur->next;

            cur->next = pre;

            pre = cur;

            cur = nxt;
        }
        
        return pre;
    }

    // ListNode* left;

    // bool isPalindrome(ListNode* head) {
    //     // 递归算法
    //     left = head;

    //     return traverse(head);
    // }

    // bool traverse(ListNode* right)
    // {
    //     if (!right)
    //     {
    //         return true;
    //     }
        
    //     bool result = traverse(right->next);

    //     result = result && (right->val == left->val);

    //     left = left->next;

    //     return result;
    // }
};
// @lc code=end

