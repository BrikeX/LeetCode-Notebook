/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
#include <cstddef>
#include <cstdlib>
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  int orangesRotting(std::vector<std::vector<int>>& grid) {
    int fresh_orange_num = 0;
    std::queue<std::pair<int, int>> frontier_rotten_oranges;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (1 == grid[i][j]) {
          ++fresh_orange_num;
        } else if (2 == grid[i][j]) {
          frontier_rotten_oranges.push(std::make_pair(i, j));
        }
      }
    }
    if (0 == fresh_orange_num) {
      return 0;
    }
    if (frontier_rotten_oranges.empty()) {
      return -1;
    }
    int min_minutes = 0;

    while (!frontier_rotten_oranges.empty()) {
      const auto rotten_num = frontier_rotten_oranges.size();

      for (std::size_t k = 0U; k != rotten_num; ++k) {
        const auto rotten_idx = frontier_rotten_oranges.front();
        frontier_rotten_oranges.pop();

        for (int i = -1; i < 2; ++i) {
          for (int j = -1; j < 2; ++j) {
            if (0 == i && 0 == j) {
              continue;
            }
            if (2 == std::abs(i) + std::abs(j)) {
              continue;
            }
            const int row = rotten_idx.first + i;
            const int col = rotten_idx.second + j;

            if (!CheckFreshOrange(grid, row, col)) {
              continue;
            }
            grid[row][col] = 2;
            frontier_rotten_oranges.push(std::make_pair(row, col));
            --fresh_orange_num;
          }
        }
      }
      ++min_minutes;
      if (fresh_orange_num <= 0) {
        break;
      }
    }
    if (fresh_orange_num > 0) {
      return -1;
    }
    return min_minutes;
  }

 private:
  static bool CheckFreshOrange(const std::vector<std::vector<int>>& grid,
                               const int i, const int j);
};

bool Solution::CheckFreshOrange(const std::vector<std::vector<int>>& grid,
                                const int i, const int j) {
  if (i < 0 || i >= grid.size()) {
    return false;
  }
  if (j < 0 || j >= grid[i].size()) {
    return false;
  }
  return 1 == grid[i][j];
}
// @lc code=end
