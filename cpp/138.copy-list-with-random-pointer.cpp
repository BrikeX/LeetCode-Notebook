/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
#include <cstddef>
#include <unordered_map>

// Definition for a Node.
// class Node {
//  public:
//   int val;
//   Node* next;
//   Node* random;

//   Node(int _val) {
//     val = _val;
//     next = NULL;
//     random = NULL;
//   }
// };

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return nullptr;
    }
    std::unordered_map<Node*, Node*> old2new_node_map;
    Node* node_ptr = head;
    while (node_ptr) {
      old2new_node_map[node_ptr] = new Node(node_ptr->val);
      node_ptr = node_ptr->next;
    }
    node_ptr = head;
    while (node_ptr) {
      old2new_node_map.at(node_ptr)->next =
          node_ptr->next ? old2new_node_map.at(node_ptr->next) : NULL;
      old2new_node_map.at(node_ptr)->random =
          node_ptr->random ? old2new_node_map.at(node_ptr->random) : NULL;

      node_ptr = node_ptr->next;
    }
    return old2new_node_map.at(head);
  }
};
// @lc code=end
