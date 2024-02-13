/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <cstddef>
#include <functional>
#include <unordered_map>
#include <utility>
#include <vector>

struct Node final {
  Node() = default;
  ~Node() = default;
  Node(const int i, const int j) : row(i), col(j) {}
  bool operator==(const Node &rhs) const {
    return (row == rhs.row) && (col == rhs.col);
  }
  bool operator!=(const Node &rhs) const { return !(*this == rhs); }

  int row = 0;
  int col = 0;
};

struct NodeHash {
  std::size_t operator()(const Node &node) const {
    return std::hash<int>()(node.row) ^ (std::hash<int>()(node.col) << 1);
  }
};

class WeightedQuickUnionUF final {
 public:
  WeightedQuickUnionUF(const std::vector<Node> &node_vec);
  ~WeightedQuickUnionUF() = default;

  int root_count() const { return root_count_; }

  bool Connected(const Node &lhs, const Node &rhs) const;
  bool Find(const Node &node, Node *parent_node) const;
  void Union(const Node &lhs, const Node &rhs);

 private:
  std::unordered_map<Node, Node, NodeHash> parent_map_;
  std::unordered_map<Node, int, NodeHash> union_size_;
  int root_count_ = 0u;
};

WeightedQuickUnionUF::WeightedQuickUnionUF(const std::vector<Node> &node_vec) {
  if (node_vec.empty()) {
    return;
  }
  root_count_ = node_vec.size();
  parent_map_.reserve(root_count_);
  union_size_.reserve(root_count_);
  for (const auto &node : node_vec) {
    parent_map_[node] = node;
    union_size_[node] = 1;
  }
}

bool WeightedQuickUnionUF::Connected(const Node &lhs, const Node &rhs) const {
  Node lhs_root;
  Node rhs_root;
  return Find(lhs, &lhs_root) && Find(rhs, &rhs_root) && lhs_root == rhs_root;
}

bool WeightedQuickUnionUF::Find(const Node &node, Node *parent_node) const {
  if (!parent_node) {
    return false;
  }
  auto it = parent_map_.find(node);
  while (parent_map_.end() != it && it->first != it->second) {
    it = parent_map_.find(it->second);
  }
  if (parent_map_.end() == it) {
    return false;
  }
  if (it->first != it->second) {
    return false;
  }
  *parent_node = it->second;

  return true;
}

void WeightedQuickUnionUF::Union(const Node &lhs, const Node &rhs) {
  Node lhs_root;
  if (!Find(lhs, &lhs_root)) {
    return;
  }
  Node rhs_root;
  if (!Find(rhs, &rhs_root)) {
    return;
  }
  if (lhs_root == rhs_root) {
    return;
  }
  if (union_size_.end() == union_size_.find(lhs_root)) {
    return;
  }
  if (union_size_.end() == union_size_.find(rhs_root)) {
    return;
  }
  if (union_size_.at(lhs_root) < union_size_.at(rhs_root)) {
    parent_map_.at(lhs_root) = rhs_root;
    union_size_.at(rhs_root) += union_size_.at(lhs_root);
  } else {
    parent_map_.at(rhs_root) = lhs_root;
    union_size_.at(lhs_root) += union_size_.at(rhs_root);
  }
  --root_count_;
}

class Solution {
 public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    return DFS(&grid);
    // return UnionFind(grid);
  }

 private:
  int DFS(std::vector<std::vector<char>> *const grid) const;
  void SearchLandByDFS(const int row, const int col,
                       std::vector<std::vector<char>> *const grid) const;
  int UnionFind(const std::vector<std::vector<char>> &grid) const;
  bool IsLand(const std::vector<std::vector<char>> &grid, const int row,
              const int col) const;

 private:
  static constexpr char kWater = '0';
  static constexpr char kLand = '1';
  static constexpr char kFoundLand = '2';
};

int Solution::DFS(std::vector<std::vector<char>> *const grid) const {
  if (!grid) {
    return 0;
  }
  int island_num = 0;
  for (int i = 0; i < (*grid).size(); ++i) {
    for (int j = 0; j < (*grid)[i].size(); ++j) {
      if (kLand != (*grid)[i][j]) {
        continue;
      }
      SearchLandByDFS(i, j, grid);
      ++island_num;
    }
  }
  return island_num;
}

void Solution::SearchLandByDFS(
    const int row, const int col,
    std::vector<std::vector<char>> *const grid) const {
  if (!grid) {
    return;
  }
  if (!IsLand(*grid, row, col)) {
    return;
  }
  (*grid)[row][col] = kFoundLand;
  SearchLandByDFS(row - 1, col, grid);
  SearchLandByDFS(row + 1, col, grid);
  SearchLandByDFS(row, col - 1, grid);
  SearchLandByDFS(row, col + 1, grid);
}

bool Solution::IsLand(const std::vector<std::vector<char>> &grid, const int row,
                      const int col) const {
  if (row < 0 || row >= grid.size()) {
    return false;
  }
  if (col < 0 || col >= grid[row].size()) {
    return false;
  }
  if (kLand != grid[row][col]) {
    return false;
  }
  return true;
}

int Solution::UnionFind(const std::vector<std::vector<char>> &grid) const {
  if (grid.empty() || grid.front().empty()) {
    return 0;
  }
  const int row_size = grid.size();
  const int col_size = grid.front().size();
  const int node_size = row_size * col_size;
  if (1u == node_size) {
    return kLand == grid[0][0] ? 1 : 0;
  }
  std::vector<Node> land_vec;
  land_vec.reserve(node_size);
  std::vector<std::pair<Node, Node>> land_pair_vec;
  land_pair_vec.reserve(node_size);

  for (int i = 0; i != row_size; ++i) {
    for (int j = 0; j != col_size; ++j) {
      if (kLand != grid[i][j]) {
        continue;
      }
      const Node curr_node(i, j);
      land_vec.emplace_back(curr_node);
      if (IsLand(grid, i - 1, j)) {
        land_pair_vec.emplace_back(std::make_pair(curr_node, Node(i - 1, j)));
      }
      if (IsLand(grid, i + 1, j)) {
        land_pair_vec.emplace_back(std::make_pair(curr_node, Node(i + 1, j)));
      }
      if (IsLand(grid, i, j - 1)) {
        land_pair_vec.emplace_back(std::make_pair(curr_node, Node(i, j - 1)));
      }
      if (IsLand(grid, i, j + 1)) {
        land_pair_vec.emplace_back(std::make_pair(curr_node, Node(i, j + 1)));
      }
    }
  }
  if (land_vec.empty()) {
    return 0;
  }
  WeightedQuickUnionUF uf(land_vec);
  for (const auto &land_pair : land_pair_vec) {
    if (uf.Connected(land_pair.first, land_pair.second)) {
      continue;
    }
    uf.Union(land_pair.first, land_pair.second);
  }
  return uf.root_count();
}
// @lc code=end
