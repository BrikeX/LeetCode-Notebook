/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <vector>

enum class NodeState { kUnknown = 0, kSearching = 1, kFinished = 2 };

class Solution {
 public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>>& prerequisites) {
    edges_.reserve(numCourses);
    node_states_.reserve(numCourses);

    for (int i = 0; i < numCourses; ++i) {
      node_states_[i] = NodeState::kUnknown;
      edges_[i] = {};
    }
    for (const auto& prerequisite : prerequisites) {
      edges_[prerequisite[1]].emplace_back(prerequisite[0]);
    }
    for (int i = 0; i < numCourses && acylic_; ++i) {
      if (NodeState::kUnknown == node_states_.at(i)) {
        CheckCycle(i);
      }
    }
    if (!acylic_) {
      return {};
    }
    for (auto& node : node_states_) {
      node.second = NodeState::kUnknown;
    }
    for (int i = 0; i < numCourses && valid_; ++i) {
      if (NodeState::kUnknown == node_states_.at(i)) {
        PostOrder(i);
      }
    }
    if (!valid_) {
      return {};
    }
    if (post_order_.size() != numCourses) {
      return {};
    }
    std::reverse(post_order_.begin(), post_order_.end());
    return post_order_;
  }

 private:
  void CheckCycle(const int node);
  void PostOrder(const int node);

 private:
  std::unordered_map<int, std::vector<int>> edges_;
  std::unordered_map<int, NodeState> node_states_;
  bool acylic_ = true;
  bool valid_ = true;
  std::vector<int> post_order_;
};

void Solution::CheckCycle(const int node) {
  if (node_states_.cend() == node_states_.find(node) ||
      edges_.cend() == edges_.find(node)) {
    acylic_ = false;
    return;
  }
  node_states_.at(node) = NodeState::kSearching;

  for (const int neighbor : edges_.at(node)) {
    if (!acylic_) {
      break;
    }
    if (node_states_.cend() == node_states_.find(neighbor)) {
      acylic_ = false;
      break;
    }
    if (NodeState::kUnknown == node_states_.at(neighbor)) {
      CheckCycle(neighbor);
    } else if (NodeState::kSearching == node_states_.at(neighbor)) {
      acylic_ = false;
      break;
    }
  }
  node_states_.at(node) = NodeState::kFinished;
}

void Solution::PostOrder(const int node) {
  if (node_states_.cend() == node_states_.find(node) ||
      edges_.cend() == edges_.find(node)) {
    valid_ = false;
    return;
  }
  node_states_.at(node) = NodeState::kFinished;

  for (const auto neighbor : edges_.at(node)) {
    if (node_states_.cend() == node_states_.find(neighbor)) {
      valid_ = false;
      return;
    }
    if (NodeState::kUnknown == node_states_.at(neighbor)) {
      PostOrder(neighbor);
    }
  }
  post_order_.emplace_back(node);
}
// @lc code=end
