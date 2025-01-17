/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <deque>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    const std::unordered_set<std::string> word_set(wordDict.cbegin(),
                                                   wordDict.cend());
    std::size_t len_max = 0U;
    for (const auto& word : word_set) {
      len_max = std::max(len_max, word.size());
    }
    std::deque<bool> dp_vec(s.size() + 1, false);
    dp_vec[0] = true;

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        const auto sub_size = i - j;
        if (sub_size > len_max) {
          break;
        }
        if (word_set.cend() == word_set.find(s.substr(j, sub_size))) {
          continue;
        }
        if (dp_vec[j]) {
          dp_vec[i] = true;
          break;
        }
      }
    }
    return dp_vec.back();
  }
};
// @lc code=end
