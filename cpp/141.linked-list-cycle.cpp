/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
#include <cstddef>
#include <unordered_set>

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    // return HashTable(head);
    return TwoPointers(head);
  }

 private:
  static bool HashTable(ListNode *const head);
  static bool TwoPointers(ListNode *const head);
};

bool Solution::HashTable(ListNode *const head) {
  if (!head) {
    return false;
  }
  std::unordered_set<ListNode *> node_set;
  ListNode *node_ptr = head;
  while (node_ptr) {
    if (node_set.cend() != node_set.find(node_ptr)) {
      return true;
    }
    node_set.emplace(node_ptr);
    node_ptr = node_ptr->next;
  }
  return false;
}

bool Solution::TwoPointers(ListNode *const head) {
  if (!head || !head->next) {
    return false;
  }
  auto slow_node_ptr = head;
  auto fast_node_ptr = head->next;
  while (fast_node_ptr != slow_node_ptr) {
    if (!fast_node_ptr->next || !fast_node_ptr->next->next) {
      return false;
    }
    slow_node_ptr = slow_node_ptr->next;
    fast_node_ptr = fast_node_ptr->next->next;
  }
  return true;
}
// @lc code=end
