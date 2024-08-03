/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  std::string addStrings(std::string num1, std::string num2) {
    std::string result;
    result.reserve(std::max(num1.size(), num2.size()) + 1);
    auto num1_rit = num1.rbegin();
    auto num2_rit = num2.rbegin();
    int carry = 0;
    int data1 = 0;
    int data2 = 0;
    int sum = 0;

    while (num1.rend() != num1_rit || num2.rend() != num2_rit) {
      data1 = 0;
      data2 = 0;

      if (num1.rend() != num1_rit) {
        data1 = *num1_rit - '0';
        ++num1_rit;
      }
      if (num2.rend() != num2_rit) {
        data2 = *num2_rit - '0';
        ++num2_rit;
      }
      sum = data1 + data2 + carry;
      carry = sum / 10;
      sum %= 10;
      result.insert(0, 1, sum + '0');
    }
    if (carry) {
      result.insert(0, 1, carry + '0');
    }
    return result;
  }
};
// @lc code=end
