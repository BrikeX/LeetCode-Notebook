/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // // 迭代算法
        // if (!list1)
        // {
        //     return list2;
        // }
        
        // if (!list2)
        // {
        //     return list1;
        // }
        
        // ListNode list_merge;

        // ListNode* node_ptr = &list_merge;

        // while (list1 && list2)
        // {
        //     if (list1->val < list2->val)
        //     {
        //         node_ptr->next = list1;

        //         list1 = list1->next;
        //     }
        //     else
        //     {
        //         node_ptr->next = list2;
                
        //         list2 = list2->next;
        //     }
            
        //     node_ptr = node_ptr->next;
        // }
        
        // node_ptr->next = !list1 ? list2 : list1;

        // return list_merge.next;

        // 递归算法
        if (!list1)
        {
            return list2;
        }
        else if (!list2)
        {
            return list1;
        }
        else if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);

            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);

            return list2;
        }
    }
};
// @lc code=end

