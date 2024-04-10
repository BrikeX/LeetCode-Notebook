/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int singleNonDuplicate(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;
    while (left < right) {
      mid = left + (right - left) / 2;
      if (mid % 2) {
        --mid;
      }
      if (nums[mid] == nums[mid + 1]) {
        left += 2;
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};
// @lc code=end
