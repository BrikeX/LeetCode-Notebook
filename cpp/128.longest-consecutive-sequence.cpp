/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <algorithm>
#include <map>
#include <vector>

class Solution {
 public:
  int longestConsecutive(std::vector<int>& nums) {
    if (nums.size() <= 1U) {
      return nums.size();
    }
    for (const int num : nums) {
      length_map_.emplace(num, 1);
    }
    auto slow_it = length_map_.rbegin();
    auto fast_it = ++length_map_.rbegin();

    while (fast_it != length_map_.rend() && slow_it != length_map_.rend()) {
      if (fast_it->first + 1 == slow_it->first) {
        fast_it->second += slow_it->second;
      }
      result_ = std::max(result_, fast_it->second);
      ++fast_it;
      ++slow_it;
    }
    return result_;
  }

 private:
  std::map<int, int> length_map_;
  int result_ = 1;
};
// @lc code=end
