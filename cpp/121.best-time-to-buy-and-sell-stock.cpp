/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <limits>
#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    if (prices.size() < 2U) {
      return 0;
    }
    int price_min = std::numeric_limits<int>::max();
    int profit_max = 0;
    int profit = 0;
    for (const auto price : prices) {
      if (price < price_min) {
        price_min = price;
      }
      profit = price - price_min;
      if (profit > profit_max) {
        profit_max = profit;
      }
    }
    return profit_max;
  }
};
// @lc code=end
