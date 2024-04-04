/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  void sortColors(std::vector<int> &nums) {
    if (nums.size() <= 1U) {
      return;
    }
    QuickSort(0, nums.size() - 1, &nums);
  }

 private:
  static void QuickSort(const int lo, const int hi,
                        std::vector<int> *const nums);
  static int Partition(const int lo, const int hi,
                       std::vector<int> *const nums);
};

void Solution::QuickSort(const int lo, const int hi,
                         std::vector<int> *const nums) {
  if (!nums) {
    return;
  }
  if (hi <= lo) {
    return;
  }
  const int j = Partition(lo, hi, nums);
  QuickSort(lo, j - 1, nums);
  QuickSort(j + 1, hi, nums);
}

int Solution::Partition(const int lo, const int hi,
                        std::vector<int> *const nums) {
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
  return j;
}
// @lc code=end
