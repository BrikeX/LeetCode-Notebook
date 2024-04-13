/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int shipWithinDays(std::vector<int>& weights, int days) {
    int weight_sum = 0;
    int weight_max = 0;
    for (const int weight : weights) {
      weight_sum += weight;
      weight_max = std::max(weight_max, weight);
    }
    if (1 == days) {
      return weight_sum;
    }
    int weight_lhs = weight_max;
    int weight_rhs = weight_sum;
    int weight_mid = 0;
    int sum_temp = 0;
    int day_min = 0;
    while (weight_lhs < weight_rhs) {
      weight_mid = weight_lhs + (weight_rhs - weight_lhs) / 2;
      day_min = 1;
      sum_temp = 0;
      for (const int weight : weights) {
        if (sum_temp + weight > weight_mid) {
          ++day_min;
          sum_temp = 0;
        }
        sum_temp += weight;
      }
      if (day_min <= days) {
        weight_rhs = weight_mid;
      } else {
        weight_lhs = weight_mid + 1;
      }
    }
    return weight_lhs;
  }
};
// @lc code=end
