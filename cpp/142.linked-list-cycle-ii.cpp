/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start

//  Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    auto slow_ptr = head;
    auto fast_ptr = head;

    while (fast_ptr && fast_ptr->next) {
      slow_ptr = slow_ptr->next;
      fast_ptr = fast_ptr->next->next;

      if (slow_ptr == fast_ptr) {
        auto node_ptr = head;
        while (node_ptr != slow_ptr) {
          node_ptr = node_ptr->next;
          slow_ptr = slow_ptr->next;
        }
        return node_ptr;
      }
    }
    return nullptr;
  }
};
// @lc code=end
