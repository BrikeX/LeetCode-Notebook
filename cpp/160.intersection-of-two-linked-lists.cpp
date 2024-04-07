/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // return HashTable(headA, headB);
    return TwoPointers(headA, headB);
  }

 private:
  static ListNode *HashTable(ListNode *const headA, ListNode *const headB);
  static ListNode *TwoPointers(ListNode *const headA, ListNode *const headB);
};

ListNode *Solution::HashTable(ListNode *const headA, ListNode *const headB) {
  if (!headA || !headB) {
    return nullptr;
  }
  ListNode *a_node_ptr = headA;
  ListNode *b_node_ptr = headB;

  std::unordered_set<ListNode *> a_node_set;

  while (a_node_ptr) {
    a_node_set.emplace(a_node_ptr);
    a_node_ptr = a_node_ptr->next;
  }
  while (b_node_ptr) {
    if (a_node_set.cend() != a_node_set.find(b_node_ptr)) {
      return b_node_ptr;
    }
    b_node_ptr = b_node_ptr->next;
  }
  return nullptr;
}

ListNode *Solution::TwoPointers(ListNode *const headA, ListNode *const headB) {
  if (!headA || !headB) {
    return nullptr;
  }
  ListNode *a_node_ptr = headA;
  ListNode *b_node_ptr = headB;

  while (a_node_ptr != b_node_ptr) {
    a_node_ptr = (nullptr == a_node_ptr) ? headB : a_node_ptr->next;
    b_node_ptr = (nullptr == b_node_ptr) ? headA : b_node_ptr->next;
  }
  return a_node_ptr;
}
// @lc code=end
