/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
#include <algorithm>

class Solution {
 public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    const int area_sum = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

    const int overlapped_width = std::min(ax2, bx2) - std::max(ax1, bx1);
    if (overlapped_width <= 0) {
      return area_sum;
    }
    const int overlapped_height = std::min(ay2, by2) - std::max(ay1, by1);
    if (overlapped_height <= 0) {
      return area_sum;
    }
    return area_sum - overlapped_width * overlapped_height;
  }
};
// @lc code=end
