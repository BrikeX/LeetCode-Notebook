/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode* next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) {
      return nullptr;
    }
    ListNode* dummy_head = new ListNode(0, head);
    ListNode* slow_ptr = dummy_head;
    ListNode* fast_ptr = head;
    for (int i = 0; i < n; ++i) {
      if (!fast_ptr) {
        return nullptr;
      }
      fast_ptr = fast_ptr->next;
    }
    while (fast_ptr) {
      fast_ptr = fast_ptr->next;
      slow_ptr = slow_ptr->next;
    }
    slow_ptr->next = slow_ptr->next->next;
    ListNode* result = dummy_head->next;
    delete dummy_head;
    return result;
  }
};
// @lc code=end
