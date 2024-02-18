/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy_head = new ListNode(0);
    ListNode* tail = dummy_head;
    int sum = 0;
    while (l1 || l2) {
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      tail->next = new ListNode(sum % 10);
      sum /= 10;
      tail = tail->next;
    }
    if (sum > 0) {
      tail->next = new ListNode(sum);
    }
    ListNode* result = dummy_head->next;
    delete dummy_head;
    return result;
  }
};
// @lc code=end
