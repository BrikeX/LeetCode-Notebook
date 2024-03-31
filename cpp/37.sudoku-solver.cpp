/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <cstddef>
#include <utility>
#include <vector>

class Solution {
 public:
  void solveSudoku(std::vector<std::vector<char>>& board) {
    if (9U != board.size() || 9U != board[0].size()) {
      return;
    }
    index_table_.reserve(81);

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if ('.' == board[i][j]) {
          index_table_.emplace_back(i, j);
        } else {
          const int digit = board[i][j] - '0';
          UpdateMemo(i, j, digit);
        }
      }
    }
    DFS(0U, &board);
  }

 private:
  bool CheckSudoku(const int row, const int col, const int digit) const;
  void UpdateMemo(const int row, const int col, const int digit);
  void ResetMemo(const int row, const int col, const int digit);
  void DFS(const std::size_t index,
           std::vector<std::vector<char>>* const board);

 private:
  std::vector<std::vector<int>> row_table_{9, std::vector<int>(9, 0)};
  std::vector<std::vector<int>> col_table_{9, std::vector<int>(9, 0)};
  std::vector<std::vector<int>> sub_table_{9, std::vector<int>(9, 0)};
  std::vector<std::pair<int, int>> index_table_;
  bool valid_ = false;
};

bool Solution::CheckSudoku(const int row, const int col,
                           const int digit) const {
  const int index = digit - 1;
  if (index < 0 || index >= 9) {
    return false;
  }
  if (row_table_[row][index] >= 1) {
    return false;
  }
  if (col_table_[col][index] >= 1) {
    return false;
  }
  const int sub_index = col / 3 + (row / 3) * 3;
  if (sub_table_[sub_index][index] >= 1) {
    return false;
  }
  return true;
}

void Solution::UpdateMemo(const int row, const int col, const int digit) {
  const int index = digit - 1;
  if (index < 0 || index >= 9) {
    return;
  }
  const int sub_index = col / 3 + (row / 3) * 3;
  ++row_table_[row][index];
  ++col_table_[col][index];
  ++sub_table_[sub_index][index];
}

void Solution::ResetMemo(const int row, const int col, const int digit) {
  const int index = digit - 1;
  if (index < 0 || index >= 9) {
    return;
  }
  const int sub_index = col / 3 + (row / 3) * 3;
  --row_table_[row][index];
  --col_table_[col][index];
  --sub_table_[sub_index][index];
}

void Solution::DFS(const std::size_t index,
                   std::vector<std::vector<char>>* const board) {
  if (!board) {
    return;
  }
  if (index_table_.size() == index) {
    valid_ = true;
    return;
  }
  const int row = index_table_[index].first;
  const int col = index_table_[index].second;
  for (int digit = 1; digit <= 9 && !valid_; ++digit) {
    if (!CheckSudoku(row, col, digit)) {
      continue;
    }
    UpdateMemo(row, col, digit);
    (*board)[row][col] = static_cast<char>(digit + '0');
    DFS(index + 1, board);
    if (!valid_) {
      (*board)[row][col] = '.';
      ResetMemo(row, col, digit);
    }
  }
}
// @lc code=end
