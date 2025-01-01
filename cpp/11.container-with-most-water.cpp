/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxArea(std::vector<int>& height) {
    if (height.size() < 2U) {
      return 0;
    }
    if (2U == height.size()) {
      return std::min(height[0], height[1]);
    }
    int lhs = 0;
    int rhs = height.size() - 1;
    int result = 0;

    while (lhs < rhs) {
      const int area = std::min(height[lhs], height[rhs]) * (rhs - lhs);
      result = std::max(result, area);
      if (height[lhs] < height[rhs]) {
        ++lhs;
      } else {
        --rhs;
      }
    }
    return result;
  }
};
// @lc code=end
