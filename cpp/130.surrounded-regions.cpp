/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  void solve(std::vector<std::vector<char>> &board) {
    row_size_ = static_cast<int>(board.size());
    if (row_size_ <= 1) {
      return;
    }
    col_size_ = static_cast<int>(board.front().size());
    if (col_size_ <= 1) {
      return;
    }
    const int last_row = row_size_ - 1;
    const int last_col = col_size_ - 1;
    for (int j = 0; j < col_size_; ++j) {
      if ('O' == board[0][j]) {
        DFS(0, j, &board);
      }
      if ('O' == board[last_row][j]) {
        DFS(last_row, j, &board);
      }
    }
    for (int i = 1; i < last_row; ++i) {
      if ('O' == board[i][0]) {
        DFS(i, 0, &board);
      }
      if ('O' == board[i][last_col]) {
        DFS(i, last_col, &board);
      }
    }
    for (int i = 0; i < row_size_; ++i) {
      for (int j = 0; j < col_size_; ++j) {
        if ('X' == board[i][j]) {
          continue;
        }
        if ('O' == board[i][j]) {
          board[i][j] = 'X';
        }
        if (kIsolated == board[i][j]) {
          board[i][j] = 'O';
        }
      }
    }
  }

 private:
  void DFS(const int row, const int col,
           std::vector<std::vector<char>> *const board) const;

 private:
  const char kIsolated = 'I';
  int row_size_ = 0;
  int col_size_ = 0;
};

void Solution::DFS(const int row, const int col,
                   std::vector<std::vector<char>> *const board) const {
  if (!board) {
    return;
  }
  if (row < 0 || row >= row_size_) {
    return;
  }
  if (col < 0 || col >= col_size_) {
    return;
  }
  if ('X' == (*board)[row][col]) {
    return;
  }
  if (kIsolated == (*board)[row][col]) {
    return;
  }
  (*board)[row][col] = kIsolated;
  DFS(row + 1, col, board);
  DFS(row - 1, col, board);
  DFS(row, col + 1, board);
  DFS(row, col - 1, board);
}
// @lc code=end
