/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    if (0 == m) {
      nums1 = nums2;
      return;
    }
    if (0 == n) {
      return;
    }
    std::vector<int> merged_vec = nums1;
    merged_vec.insert(merged_vec.begin() + m, nums2.begin(), nums2.end());

    int i = 0;
    int j = m;
    const int merged_size = m + n;

    for (int k = 0; k < merged_size; ++k) {
      if (i >= m) {
        nums1[k] = merged_vec[j++];
      } else if (j >= merged_size) {
        nums1[k] = merged_vec[i++];
      } else if (merged_vec[j] < merged_vec[i]) {
        nums1[k] = merged_vec[j++];
      } else {
        nums1[k] = merged_vec[i++];
      }
    }
  }
};
// @lc code=end
