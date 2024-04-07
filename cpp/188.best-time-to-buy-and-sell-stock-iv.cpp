/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {
 public:
  int maxProfit(int k, std::vector<int> &prices) {
    if (k <= 0 || prices.empty()) {
      return 0;
    } else if (1U == prices.size()) {
      return 0;
    }
    // dp_table[i][j] the max profit on day i and status j
    // 0 == j for none
    // 1 == j % 2 for buying
    // 0 == j % 2 for selling
    std::vector<std::vector<int>> dp_table(prices.size(),
                                           std::vector<int>(2 * k + 1, 0));
    for (int j = 1; j < 2 * k; j += 2) {
      dp_table[0][j] = -prices[0];
    }
    for (std::size_t i = 1; i < prices.size(); ++i) {
      for (int j = 0; j < 2 * k - 1; j += 2) {
        // buying
        dp_table[i][j + 1] =
            std::max(dp_table[i - 1][j + 1], dp_table[i - 1][j] - prices[i]);
        // selling
        dp_table[i][j + 2] = std::max(dp_table[i - 1][j + 2],
                                      dp_table[i - 1][j + 1] + prices[i]);
      }
    }
    return dp_table.back().back();
  }
};
// @lc code=end
