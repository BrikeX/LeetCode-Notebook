/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <cstdlib>
#include <queue>
#include <unordered_map>
#include <vector>

enum class GridType : char { kWater = '0', kLand = '1', kFoundLand = '2' };

class Solution {
 public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    return DFS(&grid);
    // return UnionFind(grid);
    // return BFS(&grid);
  }

 private:
  int DFS(std::vector<std::vector<char>> *const grid) const;
  void SearchLandByDFS(const int row, const int col,
                       std::vector<std::vector<char>> *const grid) const;
  int UnionFind(const std::vector<std::vector<char>> &grid) const;
  int BFS(std::vector<std::vector<char>> *const grid) const;
  void SearchLandByBFS(const int row, const int col,
                       std::vector<std::vector<char>> *const grid) const;
  bool IsLand(const std::vector<std::vector<char>> &grid, const int row,
              const int col) const;
};

int Solution::DFS(std::vector<std::vector<char>> *const grid) const {
  if (!grid) {
    return 0;
  }
  int island_num = 0;
  for (int i = 0; i < (*grid).size(); ++i) {
    for (int j = 0; j < (*grid)[i].size(); ++j) {
      if (!IsLand(*grid, i, j)) {
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
  (*grid)[row][col] = static_cast<char>(GridType::kFoundLand);
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
  if (static_cast<char>(GridType::kLand) != grid[row][col]) {
    return false;
  }
  return true;
}

int Solution::BFS(std::vector<std::vector<char>> *const grid) const {
  if (!grid) {
    return 0;
  }
  int island_num = 0;
  for (int i = 0; i < (*grid).size(); ++i) {
    for (int j = 0; j < (*grid)[i].size(); ++j) {
      if (!IsLand(*grid, i, j)) {
        continue;
      }
      SearchLandByBFS(i, j, grid);
      ++island_num;
    }
  }
  return island_num;
}

void Solution::SearchLandByBFS(
    const int row, const int col,
    std::vector<std::vector<char>> *const grid) const {
  if (!grid || grid->empty() || grid->front().empty()) {
    return;
  }
  if (!IsLand(*grid, row, col)) {
    return;
  }
  const int col_size = grid->front().size();
  const int source = row * col_size + col;
  std::queue<int> frontier;
  frontier.push(source);
  (*grid)[row][col] = static_cast<char>(GridType::kFoundLand);
  while (!frontier.empty()) {
    const int node = frontier.front();
    frontier.pop();
    const int node_row = node / col_size;
    const int node_col = node % col_size;
    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (0 == i && 0 == j) {
          continue;
        }
        if (2 == std::abs(i) + std::abs(j)) {
          continue;
        }
        const int row_index = node_row + i;
        const int col_index = node_col + j;
        if (!IsLand(*grid, row_index, col_index)) {
          continue;
        }
        (*grid)[row_index][col_index] = static_cast<char>(GridType::kFoundLand);
        frontier.push(row_index * col_size + col_index);
      }
    }
  }
}

class WeightedQuickUnionUF final {
 public:
  WeightedQuickUnionUF(const std::vector<std::vector<char>> &grid);
  ~WeightedQuickUnionUF() = default;

  int root_count() const { return root_count_; }

  bool Connected(const int &lhs, const int &rhs) const;
  bool Find(const int &node, int *const parent_node) const;
  void Union(const int &lhs, const int &rhs);

 private:
  std::unordered_map<int, int> parent_map_;
  std::unordered_map<int, int> union_size_;
  int root_count_ = 0;
};

WeightedQuickUnionUF::WeightedQuickUnionUF(
    const std::vector<std::vector<char>> &grid) {
  root_count_ = 0;
  if (grid.empty() || grid[0].empty()) {
    return;
  }
  const auto grid_size = grid.size() * grid[0].size();
  parent_map_.reserve(grid_size);
  union_size_.reserve(grid_size);
  int index = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (static_cast<char>(GridType::kLand) == grid[i][j]) {
        parent_map_[index] = index;
        union_size_[index] = 1;
        ++root_count_;
      }
      ++index;
    }
  }
}

bool WeightedQuickUnionUF::Connected(const int &lhs, const int &rhs) const {
  int lhs_root = 0;
  int rhs_root = 0;
  return Find(lhs, &lhs_root) && Find(rhs, &rhs_root) && lhs_root == rhs_root;
}

bool WeightedQuickUnionUF::Find(const int &node, int *const parent_node) const {
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

void WeightedQuickUnionUF::Union(const int &lhs, const int &rhs) {
  int lhs_root = 0;
  if (!Find(lhs, &lhs_root)) {
    return;
  }
  int rhs_root = 0;
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

int Solution::UnionFind(const std::vector<std::vector<char>> &grid) const {
  if (grid.empty() || grid.front().empty()) {
    return 0;
  }
  const int row_size = grid.size();
  const int col_size = grid.front().size();
  if (1 == row_size * col_size) {
    return static_cast<char>(GridType::kLand) == grid[0][0] ? 1 : 0;
  }
  WeightedQuickUnionUF uf(grid);
  int index = 0;
  for (int i = 0; i < row_size; ++i) {
    for (int j = 0; j < col_size; ++j) {
      if (static_cast<char>(GridType::kLand) == grid[i][j]) {
        if (IsLand(grid, i - 1, j)) {
          uf.Union(index, (i - 1) * col_size + j);
        }
        if (IsLand(grid, i + 1, j)) {
          uf.Union(index, (i + 1) * col_size + j);
        }
        if (IsLand(grid, i, j - 1)) {
          uf.Union(index, i * col_size + (j - 1));
        }
        if (IsLand(grid, i, j + 1)) {
          uf.Union(index, i * col_size + (j + 1));
        }
      }
      ++index;
    }
  }
  return uf.root_count();
}
// @lc code=end
