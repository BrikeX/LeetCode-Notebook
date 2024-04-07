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
    edges_.reserve(prerequisites.size());
    node_states_.reserve(numCourses);

    for (int i = 0; i < numCourses; ++i) {
      node_states_[i] = NodeState::kUnknown;
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
  node_states_.at(node) = NodeState::kSearching;
  const auto it = edges_.find(node);
  if (edges_.cend() == it) {
    node_states_[node] = NodeState::kFinished;
    return;
  }
  for (const int neighbor : it->second) {
    if (NodeState::kUnknown == node_states_.at(neighbor)) {
      DFS(neighbor);
      if (!valid_) {
        return;
      }
    } else if (NodeState::kSearching == node_states_.at(neighbor)) {
      valid_ = false;
      return;
    }
  }
  node_states_.at(node) = NodeState::kFinished;
}
// @lc code=end
