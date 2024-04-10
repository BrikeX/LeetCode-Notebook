/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int hIndex(std::vector<int>& citations) {
    if (citations.empty()) {
      return 0;
    } else if (1U == citations.size()) {
      return citations.front() >= 1 ? 1 : 0;
    }
    std::sort(citations.rbegin(), citations.rend());
    int h_index = 0;
    int index = 0;
    const int size = citations.size();
    for (int i = 0; i < size; ++i) {
      index = i + 1;
      if (citations[i] >= index) {
        h_index = index;
      }
    }
    return h_index;
  }
};
// @lc code=end
