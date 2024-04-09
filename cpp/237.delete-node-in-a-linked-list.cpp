/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
#include <cstddef>
#include <utility>

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode* next;
//   ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
 public:
  void deleteNode(ListNode* node) {
    if (!node || !node->next) {
      return;
    }
    node->val = std::move(node->next->val);
    node->next = node->next->next;
  }
};
// @lc code=end
