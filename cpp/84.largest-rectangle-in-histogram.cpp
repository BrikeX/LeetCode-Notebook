/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <vector>

class Solution {
 public:
  int largestRectangleArea(std::vector<int> &heights) {
    if (heights.empty()) {
      return 0;
    } else if (1U == heights.size()) {
      return heights.front();
    }
    int result = 0;
    heights.reserve(heights.size() + 2U);
    heights.insert(heights.begin(), 0);
    heights.emplace_back(0);
    const int heights_size = static_cast<int>(heights.size());
    std::stack<int> istk;
    int curr = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < heights_size; ++i) {
      while (!istk.empty() && heights[istk.top()] > heights[i]) {
        curr = istk.top();
        istk.pop();
        left = istk.top() + 1;
        right = i - 1;
        result = std::max(result, (right - left + 1) * heights[curr]);
      }
      istk.push(i);
    }
    return result;
  }
};
// @lc code=end
