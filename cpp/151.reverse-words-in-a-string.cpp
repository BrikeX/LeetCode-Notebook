/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <sstream>
#include <string>
#include <utility>

class Solution {
 public:
  std::string reverseWords(std::string s) {
    std::istringstream iss(s);
    std::string result;
    std::string word;
    while (iss >> word) {
      if (result.empty()) {
        result = std::move(word);
      } else {
        result = std::move(word + " " + result);
      }
    }
    return result;
  }
};
// @lc code=end
