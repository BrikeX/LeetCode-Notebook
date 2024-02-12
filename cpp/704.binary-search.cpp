/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    auto beg = nums.begin();
    auto end = nums.end();
    auto mid = beg + (end - beg) / 2;

    while (end != mid && *mid != target) {
      if (target < *mid) {
        end = mid;
      } else {
        beg = mid + 1;
      }
      mid = beg + (end - beg) / 2;
    }
    return (nums.end() == mid || *mid != target) ? -1 : (mid - nums.begin());
  }
};
// @lc code=end
