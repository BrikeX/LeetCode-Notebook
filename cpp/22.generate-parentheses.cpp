/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    if (0 == n) {
      return result_;
    } else if (1 == n) {
      result_.emplace_back("()");
      return result_;
    }
    result_.reserve(n * n);
    svec_.reserve(n * 2);
    Backtracking(n, 0, 0);

    return result_;
  }

 private:
  void Backtracking(const int pair_num, const int lhs_num, const int rhs_num);

 private:
  std::vector<std::string> result_;
  std::string svec_;
};

void Solution::Backtracking(const int pair_num, const int lhs_num,
                            const int rhs_num) {
  if (lhs_num == pair_num && rhs_num == pair_num) {
    result_.push_back(svec_);
    return;
  }
  if (lhs_num < pair_num) {
    svec_.push_back('(');
    Backtracking(pair_num, lhs_num + 1, rhs_num);
    svec_.pop_back();
  }
  if (rhs_num < lhs_num) {
    svec_.push_back(')');
    Backtracking(pair_num, lhs_num, rhs_num + 1);
    svec_.pop_back();
  }
}
// @lc code=end
