/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int compress(std::vector<char>& chars) {
    const int size = chars.size();
    int write_index = 0;
    int left_index = 0;
    for (int read_index = 0; read_index < size; ++read_index) {
      if (size - 1 == read_index ||
          chars[read_index] != chars[read_index + 1]) {
        chars[write_index++] = chars[read_index];
        int num = read_index - left_index + 1;
        if (num > 1) {
          const int anchor_index = write_index;
          while (num > 0) {
            chars[write_index++] = num % 10 + '0';
            num /= 10;
          }
          std::reverse(chars.begin() + anchor_index,
                       chars.begin() + write_index);
        }
        left_index = read_index + 1;
      }
    }
    return write_index;
  }
};
// @lc code=end
