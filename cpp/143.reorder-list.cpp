/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
 public:
  void reorderList(ListNode *head) {
    auto mid_ptr = FindMidNode(head);
    if (!mid_ptr || !mid_ptr->next) {
      return;
    }
    auto lhs_ptr = head;
    auto rhs_ptr = mid_ptr->next;

    mid_ptr->next = nullptr;
    rhs_ptr = ReverseList(rhs_ptr);

    MergeList(lhs_ptr, rhs_ptr);
  }

 private:
  ListNode *FindMidNode(ListNode *const head);
  ListNode *ReverseList(ListNode *const head);
  void MergeList(ListNode *lhs, ListNode *rhs);
};

ListNode *Solution::FindMidNode(ListNode *const head) {
  if (!head) {
    return nullptr;
  }
  auto slow_ptr = head;
  auto fast_ptr = head;

  while (fast_ptr->next && fast_ptr->next->next) {
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;
  }
  return slow_ptr;
}

ListNode *Solution::ReverseList(ListNode *const head) {
  if (!head) {
    return nullptr;
  }
  if (!head->next) {
    return head;
  }
  auto curr_ptr = head;
  ListNode *prev_ptr = nullptr;
  ListNode *old_next_ptr = nullptr;
  while (curr_ptr) {
    old_next_ptr = curr_ptr->next;
    curr_ptr->next = prev_ptr;
    prev_ptr = curr_ptr;
    curr_ptr = old_next_ptr;
  }
  return prev_ptr;
}

void Solution::MergeList(ListNode *lhs, ListNode *rhs) {
  ListNode *lhs_next_ptr = nullptr;
  ListNode *rhs_next_ptr = nullptr;

  while (lhs && rhs) {
    lhs_next_ptr = lhs->next;
    rhs_next_ptr = rhs->next;

    lhs->next = rhs;
    lhs = lhs_next_ptr;

    rhs->next = lhs;
    rhs = rhs_next_ptr;
  }
}
// @lc code=end
