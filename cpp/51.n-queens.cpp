/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    result_.clear();
    if (1 == n) {
      result_.push_back({"Q"});
      return result_;
    } else if (n < 4) {
      return result_;
    }
    std::vector<std::string> chessboard(n, std::string(n, '.'));
    Backtracking(0, &chessboard);

    return result_;
  }

 private:
  void Backtracking(const int row, std::vector<std::string> *const chessboard);
  bool Check(const int row, const int col,
             const std::vector<std::string> &chessboard) const;

 private:
  std::vector<std::vector<std::string>> result_;
};

void Solution::Backtracking(const int row,
                            std::vector<std::string> *const chessboard) {
  if (!chessboard || chessboard->empty()) {
    return;
  }
  if (row >= chessboard->size()) {
    result_.push_back(*chessboard);
    return;
  }
  for (int j = 0; j < (*chessboard)[row].size(); ++j) {
    if (!Check(row, j, *chessboard)) {
      continue;
    }
    (*chessboard)[row][j] = 'Q';
    Backtracking(row + 1, chessboard);
    (*chessboard)[row][j] = '.';
  }
}

bool Solution::Check(const int row, const int col,
                     const std::vector<std::string> &chessboard) const {
  if (chessboard.empty()) {
    return false;
  }
  if (row < 0 || row >= chessboard.size()) {
    return false;
  }
  if (col < 0 || col >= chessboard[row].size()) {
    return false;
  }
  // check the same column
  for (int i = 0; i < chessboard.size(); ++i) {
    if ('Q' == chessboard[i][col]) {
      return false;
    }
  }
  // check the upper diagonals
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
    if ('Q' == chessboard[i][j]) {
      return false;
    }
  }
  for (int i = row - 1, j = col + 1; i >= 0 && j < chessboard[i].size();
       --i, ++j) {
    if ('Q' == chessboard[i][j]) {
      return false;
    }
  }
  return true;
}
// @lc code=end
