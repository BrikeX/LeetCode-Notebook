/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>> &intervals) {
    if (intervals.empty()) {
      return {{}};
    } else if (1U == intervals.size()) {
      return intervals;
    }
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int> &lhs, const std::vector<int> &rhs) {
                return lhs.front() < rhs.front();
              });
    std::vector<std::vector<int>> result;
    result.reserve(intervals.size());
    int start = intervals.front().front();
    int end = intervals.front().back();
    for (const auto &interval : intervals) {
      if (interval.front() <= end) {
        end = std::max(end, interval.back());
      } else {
        result.emplace_back(std::vector<int>{start, end});
        start = interval.front();
        end = interval.back();
      }
    }
    result.emplace_back(std::vector<int>{start, end});
    return result;
  }
};
// @lc code=end
