/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include <string>
#include <vector>

enum class PalindromeType { kFalse = 0, kTrue = 1, kUnknown = 2 };

class Solution {
 public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    memo_.resize(s.size(), std::vector<PalindromeType>(
                               s.size(), PalindromeType::kUnknown));
    DFS(s, 0);
    return result_;
  }

 private:
  void DFS(const std::string &str, const int idx);
  PalindromeType CheckPalindrome(const std::string &str, const int i,
                                 const int j);

 private:
  std::vector<std::vector<std::string>> result_;
  std::vector<std::string> palindrome_str_;
  std::vector<std::vector<PalindromeType>> memo_;
};

void Solution::DFS(const std::string &str, const int idx) {
  if (idx == str.size()) {
    result_.push_back(palindrome_str_);
    return;
  }
  for (auto j = idx; j < str.size(); ++j) {
    if (PalindromeType::kTrue == CheckPalindrome(str, idx, j)) {
      palindrome_str_.push_back(str.substr(idx, j - idx + 1));
      DFS(str, j + 1);
      palindrome_str_.pop_back();
    }
  }
}

PalindromeType Solution::CheckPalindrome(const std::string &str, const int i,
                                         const int j) {
  if (i < 0 || i >= memo_.size() || j < 0 || j >= memo_[i].size() || i < 0 ||
      i >= str.size()) {
    return PalindromeType::kFalse;
  }
  if (PalindromeType::kUnknown == memo_[i][j]) {
    if (i >= j) {
      memo_[i][j] = PalindromeType::kTrue;
    } else {
      memo_[i][j] = str[i] == str[j] ? CheckPalindrome(str, i + 1, j - 1)
                                     : PalindromeType::kFalse;
    }
  }
  return memo_[i][j];
}
// @lc code=end
