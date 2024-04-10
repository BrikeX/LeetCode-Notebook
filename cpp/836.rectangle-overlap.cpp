/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
    return (std::min(rec1[2], rec2[2]) > std::max(rec1[0], rec2[0]) &&
            std::min(rec1[3], rec2[3]) > std::max(rec1[1], rec2[1]));
  }
};
// @lc code=end
