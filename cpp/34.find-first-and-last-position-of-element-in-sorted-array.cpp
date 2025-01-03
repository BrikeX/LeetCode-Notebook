/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    int left = -1;
    int right = -1;
    int beg = 0;
    int end = nums.size() - 1;
    int mid = 0;

    while (beg <= end) {
      mid = beg + (end - beg) / 2;
      if (target == nums[mid]) {
        left = mid;
        end = mid - 1;
      } else if (target < nums[mid]) {
        end = mid - 1;
      } else {
        beg = mid + 1;
      }
    }

    beg = 0;
    end = nums.size() - 1;

    while (beg <= end) {
      mid = beg + (end - beg) / 2;
      if (target == nums[mid]) {
        right = mid;
        beg = mid + 1;
      } else if (target < nums[mid]) {
        end = mid - 1;
      } else {
        beg = mid + 1;
      }
    }
    return {left, right};
  }
};
// @lc code=end
