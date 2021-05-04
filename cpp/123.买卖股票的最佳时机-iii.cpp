/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // DP
        // profit[i][2][0] = max(profit[i-1][2][0], profit[i-1][2][1] + prices[i])
        // profit[i][2][1] = max(profit[i-1][2][1], profit[i-1][1][0] - prices[i])
        // profit[i][1][0] = max(profit[i-1][1][0], profit[i-1][1][1] + prices[i])
        // profit[i][1][1] = max(profit[i-1][1][1], profit[i-1][0][0] - prices[i])
                        // = max(profit[i-1][1][1], -prices[i])

        int profit_2_0 = 0, profit_2_1 = INT_MIN;

        int profit_1_0 = 0, profit_1_1 = INT_MIN;

        for (size_t i = 0; i < prices.size(); i++)
        {
            profit_2_0 = max(profit_2_0, profit_2_1 + prices[i]);

            profit_2_1 = max(profit_2_1, profit_1_0 - prices[i]);

            profit_1_0 = max(profit_1_0, profit_1_1 + prices[i]);

            profit_1_1 = max(profit_1_1, -prices[i]);
        }
        
        return profit_2_0;
    }
};
// @lc code=end

