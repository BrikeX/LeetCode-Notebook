/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <unordered_map>
#include <vector>

enum class NodeState { kUnknown = 0, kSearching = 1, kFinished = 2 };

class Solution {
 public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    edges_.reserve(numCourses);
    node_states_.reserve(numCourses);

    for (int i = 0; i < numCourses; ++i) {
      node_states_[i] = NodeState::kUnknown;
      edges_[i] = {};
    }
    for (const auto& prerequisite : prerequisites) {
      edges_[prerequisite[1]].emplace_back(prerequisite[0]);
    }
    for (int i = 0; i < numCourses && valid_; ++i) {
      if (NodeState::kUnknown == node_states_.at(i)) {
        DFS(i);
      }
    }
    return valid_;
  }

 private:
  void DFS(const int node);

 private:
  std::unordered_map<int, std::vector<int>> edges_;
  std::unordered_map<int, NodeState> node_states_;
  bool valid_ = true;
};

void Solution::DFS(const int node) {
  if (node_states_.cend() == node_states_.find(node) ||
      edges_.cend() == edges_.find(node)) {
    valid_ = false;
    return;
  }
  node_states_.at(node) = NodeState::kSearching;

  for (const int neighbor : edges_.at(node)) {
    if (!valid_) {
      break;
    }
    if (NodeState::kUnknown == node_states_.at(neighbor)) {
      DFS(neighbor);
    } else if (NodeState::kSearching == node_states_.at(neighbor)) {
      valid_ = false;
      break;
    }
  }
  node_states_.at(node) = NodeState::kFinished;
}
// @lc code=end
