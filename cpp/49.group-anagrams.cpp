/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(
      std::vector<std::string> &strs) {
    if (strs.empty()) {
      return {{}};
    } else if (1U == strs.size()) {
      return {strs};
    }
    std::vector<std::vector<std::string>> result;
    result.reserve(strs.size());
    std::unordered_map<std::string, std::vector<std::size_t>> anagrams_map;
    anagrams_map.reserve(strs.size());

    for (std::size_t i = 0U; i < strs.size(); ++i) {
      std::string str = strs[i];
      std::sort(str.begin(), str.end());
      anagrams_map[std::move(str)].emplace_back(i);
    }
    for (const auto &anagrams_pair : anagrams_map) {
      std::vector<std::string> anagrams;
      anagrams.reserve(anagrams_pair.second.size());
      for (const auto i : anagrams_pair.second) {
        anagrams.emplace_back(strs[i]);
      }
      result.emplace_back(std::move(anagrams));
    }
    return result;
  }
};
// @lc code=end
