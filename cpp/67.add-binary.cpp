/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  std::string addBinary(std::string a, std::string b) {
    std::string result;
    result.reserve(std::max(a.size(), b.size()) + 1U);
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int carry = 0;
    while (i >= 0 || j >= 0) {
      int m = 0;
      int n = 0;
      if (i >= 0) {
        m = a[i] - '0';
        --i;
      }
      if (j >= 0) {
        n = b[j] - '0';
        --j;
      }
      int sum = m + n + carry;
      carry = sum / 2;
      sum %= 2;
      result.insert(result.begin(), static_cast<char>('0' + sum));
    }
    if (1 == carry) {
      result.insert(result.begin(), '1');
    }
    return result;
  }
};
// @lc code=end
