/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    const int size = static_cast<int>(nums.size());
    if (1 == size) {
      return nums.front();
    }
    const int index = size - k;
    return QuickSelect(0, size - 1, index, &nums);
  }

 private:
  static int QuickSelect(const int lo, const int hi, const int index,
                         std::vector<int>* const nums);
};

int Solution::QuickSelect(const int lo, const int hi, const int index,
                          std::vector<int>* const nums) {
  if (lo == hi) {
    return (*nums)[lo];
  }
  int i = lo;
  int j = hi + 1;
  const auto val = (*nums)[lo];
  while (true) {
    while ((*nums)[++i] < val) {
      if (hi == i) {
        break;
      }
    }
    while (val < (*nums)[--j]) {
      if (lo == j) {
        break;
      }
    }
    if (i >= j) {
      break;
    }
    std::swap((*nums)[i], (*nums)[j]);
  }
  std::swap((*nums)[lo], (*nums)[j]);

  if (index == j) {
    return (*nums)[j];
  } else if (index < j) {
    return QuickSelect(lo, j - 1, index, nums);
  }
  return QuickSelect(j + 1, hi, index, nums);
}
// @lc code=end
