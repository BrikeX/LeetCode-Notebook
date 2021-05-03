/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // DP
        int profit_0 = 0, profit_1 = INT_MIN;

        int profit_tmp;

        int profit_0_old = 0;

        for (size_t i = 0; i < prices.size(); i++)
        {
            profit_tmp = profit_0;

            profit_0 = max(profit_0, profit_1 + prices[i]);

            profit_1 = max(profit_1, profit_0_old - prices[i]);

            profit_0_old = profit_tmp;
        }
        
        return profit_0;
    }
};
// @lc code=end

