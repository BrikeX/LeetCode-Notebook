/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::string> topKFrequent(std::vector<std::string>& words,
                                        int k) {
    std::unordered_map<std::string, int> word_count_map_;
    word_count_map_.reserve(words.size());
    for (const auto& word : words) {
      ++word_count_map_[word];
    }
    std::vector<std::string> result;
    result.reserve(words.size());
    for (const auto& word_count_pair : word_count_map_) {
      result.emplace_back(word_count_pair.first);
    }
    std::sort(result.begin(), result.end(),
              [&](const std::string& lhs, const std::string& rhs) {
                return word_count_map_.at(lhs) == word_count_map_.at(rhs)
                           ? lhs < rhs
                           : word_count_map_.at(lhs) > word_count_map_.at(rhs);
              });
    result.erase(result.begin() + k, result.end());
    return result;
  }
};
// @lc code=end
