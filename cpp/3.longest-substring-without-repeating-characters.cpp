/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    // return TwoPointers(s);
    return SlidingWindow(s);
  }

 private:
  int TwoPointers(const std::string s) const;
  int SlidingWindow(const std::string s) const;
};

int Solution::SlidingWindow(const std::string s) const {
  if (s.empty()) {
    return 0;
  } else if (1u == s.size()) {
    return 1;
  } else if (2u == s.size()) {
    return s[0] == s[1] ? 1 : 2;
  }
  std::unordered_map<char, int> window;
  int left_index = 0;
  int right_index = 0;
  int result = 0;
  char left_char = '\0';
  char right_char = '\0';
  while (right_index < s.size()) {
    right_char = s[right_index];
    ++right_index;
    ++window[right_char];

    while (window[right_char] > 1) {
      left_char = s[left_index];
      ++left_index;
      --window[left_char];
    }
    result = std::max(result, right_index - left_index);
  }
  return result;
}

int Solution::TwoPointers(const std::string s) const {
  if (s.empty()) {
    return 0;
  } else if (1u == s.size()) {
    return 1;
  } else if (2u == s.size()) {
    return s[0] == s[1] ? 1 : 2;
  }
  std::unordered_set<char> sub_set;
  sub_set.insert(s[0]);
  std::size_t len_max = 1;
  auto slow_it = s.begin();
  auto fast_it = s.begin() + 1;
  while (s.end() != fast_it) {
    if (sub_set.end() == sub_set.find(*fast_it)) {
      sub_set.insert(*fast_it);
      len_max = std::max(len_max, sub_set.size());
      ++fast_it;
    } else {
      sub_set.clear();
      ++slow_it;
      fast_it = slow_it;
    }
  }
  return len_max;
}
// @lc code=end
