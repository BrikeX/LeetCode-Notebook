/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <cstddef>
#include <stack>
#include <string>

class Solution {
 public:
  bool isValid(std::string s) {
    if (s.size() < 2U) {
      return false;
    }
    if (')' == s.front() || ']' == s.front() || '}' == s.front()) {
      return false;
    }
    std::stack<char> cstack;
    for (std::size_t i = 0; i < s.size(); ++i) {
      if (')' == s[i] || ']' == s[i] || '}' == s[i]) {
        if (cstack.empty()) {
          return false;
        }
        if ((')' == s[i] && '(' == cstack.top()) ||
            (']' == s[i] && '[' == cstack.top()) ||
            ('}' == s[i] && '{' == cstack.top())) {
          cstack.pop();
        } else {
          return false;
        }
      } else {
        cstack.push(s[i]);
      }
    }
    return cstack.empty();
  }
};
// @lc code=end
