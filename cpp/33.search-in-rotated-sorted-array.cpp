/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    if (1U == nums.size()) {
      return target == nums.front() ? 0 : -1;
    }
    int lhs = 0;
    int rhs = nums.size() - 1;
    int mid = 0;
    while (lhs <= rhs) {
      mid = lhs + (rhs - lhs) / 2;
      if (target == nums[mid]) {
        return mid;
      }
      if (nums[lhs] <= nums[mid]) {
        if (nums[lhs] <= target && target < nums[mid]) {
          rhs = mid - 1;
        } else {
          lhs = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[rhs]) {
          lhs = mid + 1;
        } else {
          rhs = mid - 1;
        }
      }
    }
    return -1;
  }
};
// @lc code=end
