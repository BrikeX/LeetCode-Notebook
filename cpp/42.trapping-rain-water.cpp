/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <vector>

class Solution {
 public:
  int trap(std::vector<int>& height) {
    const int size = static_cast<int>(height.size());
    if (size < 1) {
      return 0;
    }
    int result = 0;
    std::stack<int> istk;
    int top = 0;
    int left = 0;
    int curr_width = 0;
    int curr_height = 0;
    for (int i = 0; i < size; ++i) {
      while (!istk.empty() && height[i] > height[istk.top()]) {
        top = istk.top();
        istk.pop();
        if (istk.empty()) {
          break;
        }
        left = istk.top();
        curr_width = i - left - 1;
        curr_height = std::min(height[i], height[left]) - height[top];
        result += curr_width * curr_height;
      }
      istk.push(i);
    }
    return result;
  }
};
// @lc code=end
