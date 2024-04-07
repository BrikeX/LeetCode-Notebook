/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
  ListNode* reverseList(ListNode* head) {
    if (!head) {
      return nullptr;
    } else if (!head->next) {
      return head;
    }
    ListNode* prev_node = nullptr;
    ListNode* curr_node = head;
    ListNode* old_next = nullptr;
    while (curr_node) {
      old_next = curr_node->next;
      curr_node->next = prev_node;
      prev_node = curr_node;
      curr_node = old_next;
    }
    return prev_node;
  }
};
// @lc code=end
