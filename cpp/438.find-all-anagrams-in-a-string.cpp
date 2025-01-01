/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> findAnagrams(std::string s, std::string p) {
    const int s_size = s.size();
    const int p_size = p.size();
    if (s_size < p_size) {
      return {};
    }
    std::vector<int> result;
    result.reserve(s.size());

    std::vector<int> alphabet_count(26, 0);
    for (int i = 0; i < p_size; ++i) {
      ++alphabet_count[s[i] - 'a'];
      --alphabet_count[p[i] - 'a'];
    }
    int diff = 0;
    for (const int count : alphabet_count) {
      if (0 != count) {
        ++diff;
      }
    }
    if (0 == diff) {
      result.emplace_back(0);
    }
    for (int i = 0; i < s_size - p_size; ++i) {
      if (1 == alphabet_count[s[i] - 'a']) {
        --diff;
      } else if (0 == alphabet_count[s[i] - 'a']) {
        ++diff;
      }
      --alphabet_count[s[i] - 'a'];

      if (-1 == alphabet_count[s[i + p_size] - 'a']) {
        --diff;
      } else if (0 == alphabet_count[s[i + p_size] - 'a']) {
        ++diff;
      }
      ++alphabet_count[s[i + p_size] - 'a'];

      if (0 == diff) {
        result.emplace_back(i + 1);
      }
    }
    return result;
  }
};
// @lc code=end
