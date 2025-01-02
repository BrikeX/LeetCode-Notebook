/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    if (word.empty()) {
      return false;
    }
    if (board.empty() || board[0].empty()) {
      return false;
    }
    const auto board_size = board.size() * board[0].size();
    board_counter_.reserve(board_size);
    word_counter_.reserve(word.size());

    for (int row = 0; row < board.size(); ++row) {
      for (int col = 0; col < board[row].size(); ++col) {
        if (board_counter_.cend() == board_counter_.find(board[row][col])) {
          board_counter_[board[row][col]] = 1;
        } else {
          ++board_counter_[board[row][col]];
        }
      }
    }
    for (const auto ch : word) {
      if (word_counter_.cend() == word_counter_.find(ch)) {
        word_counter_[ch] = 1;
      } else {
        ++word_counter_[ch];
      }
    }
    for (const auto& [ch, num] : word_counter_) {
      if (board_counter_.cend() == board_counter_.find(ch) ||
          board_counter_.at(ch) < num) {
        return false;
      }
    }
    marked_.reserve(board_size);

    for (int row = 0; row < board.size(); ++row) {
      for (int col = 0; col < board[row].size(); ++col) {
        if (word.front() == board[row][col]) {
          marked_.clear();
          DFS(board, word, 0, row, col);
        }
        if (existence_) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  void DFS(const std::vector<std::vector<char>>& board, const std::string& word,
           const int idx, const int row, const int col);

 private:
  std::unordered_map<char, int> board_counter_;
  std::unordered_map<char, int> word_counter_;

  std::unordered_set<int> marked_;
  bool existence_ = false;
};

void Solution::DFS(const std::vector<std::vector<char>>& board,
                   const std::string& word, const int idx, const int row,
                   const int col) {
  if (row < 0 || row >= board.size() || col < 0 || col >= board[row].size() ||
      idx < 0 || idx >= word.size()) {
    return;
  }
  if (board[row][col] != word[idx]) {
    return;
  }
  if (idx + 1 == word.size()) {
    existence_ = true;
    return;
  }
  const auto marked_idx = row * board[row].size() + col;
  marked_.emplace(marked_idx);

  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      if (0 == i && 0 == j) {
        continue;
      }
      if (2 == std::abs(i) + std::abs(j)) {
        continue;
      }
      const auto new_row = row + i;
      const auto new_col = col + j;
      const auto new_idx = idx + 1;

      if (new_row < 0 || new_row >= board.size() || new_col < 0 ||
          new_col >= board[row].size() || new_idx < 0 ||
          new_idx >= word.size()) {
        continue;
      }
      if (marked_.cend() != marked_.find(new_row * board[0].size() + new_col)) {
        continue;
      }
      DFS(board, word, new_idx, new_row, new_col);
      if (existence_) {
        return;
      }
    }
  }
  marked_.erase(marked_idx);
}
// @lc code=end
