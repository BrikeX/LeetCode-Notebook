/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    if (9U != board.size() || 9U != board[0].size()) {
      return false;
    }
    std::vector<std::vector<int>> row_table(9, std::vector<int>(9, 0));
    std::vector<std::vector<int>> col_table(9, std::vector<int>(9, 0));
    std::vector<std::vector<int>> sub_table(9, std::vector<int>(9, 0));
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if ('.' == board[i][j]) {
          continue;
        }
        const int index = board[i][j] - '1';
        if (row_table[i][index] >= 1) {
          return false;
        }
        if (col_table[j][index] >= 1) {
          return false;
        }
        const int sub_index = j / 3 + (i / 3) * 3;
        if (sub_table[sub_index][index] >= 1) {
          return false;
        }
        ++row_table[i][index];
        ++col_table[j][index];
        ++sub_table[sub_index][index];
      }
    }
    return true;
  }
};
// @lc code=end
