/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l_result = new ListNode(0);

        ListNode* l_tmp = l_result;
        
        int sum = 0;

        while (l1 || l2)
        {
            if (l1)
            {
                sum += l1->val;

                l1 = l1->next;
            }
            
            if (l2)
            {
                sum += l2->val;

                l2 = l2->next;
            }

            l_tmp->next = new ListNode(sum % 10);
            
            sum /= 10;

            l_tmp = l_tmp->next;
        }

        if (sum)
        {
            l_tmp->next = new ListNode(1);
        }
        
        return l_result->next;
    }
};
// @lc code=end

