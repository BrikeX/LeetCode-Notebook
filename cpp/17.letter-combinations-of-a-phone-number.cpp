/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) {
      return {};
    }
    DFS(digits, 0);
    return result_;
  }

 private:
  void DFS(const std::string &digits, const int index);

 private:
  std::string combinations_;
  std::vector<std::string> result_;

  const std::unordered_map<char, std::string> kPhoneKeyboard_ = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
};

void Solution::DFS(const std::string &digits, const int index) {
  if (index == digits.size()) {
    result_.push_back(combinations_);
    return;
  }
  if (index < 0 || index >= digits.size()) {
    return;
  }
  if (kPhoneKeyboard_.cend() == kPhoneKeyboard_.find(digits[index])) {
    return;
  }
  const auto &letters = kPhoneKeyboard_.at(digits[index]);
  for (const auto ch : letters) {
    combinations_.push_back(ch);
    DFS(digits, index + 1);
    combinations_.pop_back();
  }
}
// @lc code=end
