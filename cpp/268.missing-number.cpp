/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int missingNumber(std::vector<int>& nums) {
    int result = 0;
    const int size = nums.size();
    for (int i = 0; i < size; ++i) {
      result += (i + 1);
      result -= nums[i];
    }
    return result;
  }
};
// @lc code=end
