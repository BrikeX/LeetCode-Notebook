/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    int result = std::numeric_limits<int>::lowest();
    int fmax = 1;
    int fmin = 1;
    int temp = 1;
    for (const auto num : nums) {
      temp = fmax;
      fmax = std::max(std::max(fmax * num, fmin * num), num);
      fmin = std::min(std::min(temp * num, fmin * num), num);
      result = std::max(result, fmax);
    }
    return result;
  }
};
// @lc code=end
