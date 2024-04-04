/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include <cstddef>
#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int> &prices) {
    if (prices.size() < 2U) {
      return 0;
    }
    int result = 0;
    int profit = 0;
    for (std::size_t i = 1U; i < prices.size(); ++i) {
      profit = prices[i] - prices[i - 1];
      if (profit > 0) {
        result += profit;
      }
    }
    return result;
  }
};
// @lc code=end
