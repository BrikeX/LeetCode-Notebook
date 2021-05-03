/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // DP
        int profit_0 = 0, profit_1 = INT_MIN;

        for (size_t i = 0; i < prices.size(); i++)
        {
            profit_0 = max(profit_0, profit_1 + prices[i]);

            profit_1 = max(profit_1, -prices[i]);
        }
        
        return profit_0;

        // // DP，空间复杂度有待改进
        // int day_max = prices.size();

        // int profit[day_max][2];

        // for (size_t i = 0; i < day_max; i++)
        // {
        //     if (i == 0)
        //     {
        //         profit[i][0] = 0;

        //         profit[i][1] = -prices[i];
            
        //         continue;
        //     }
            
        //     profit[i][0] = max(profit[i-1][0], profit[i-1][1] + prices[i]);

        //     profit[i][1] = max(profit[i-1][1], -prices[i]);
        // }

        // return profit[day_max-1][0];

        // // 暴力枚举，超时
        // int result = 0;

        // for (size_t i = 0; i < prices.size() - 1; i++)
        // {
        //     for (size_t j = i + 1; j < prices.size(); j++)
        //     {
        //         result = max(result, prices[j] - prices[i]);
        //     }
        // }
        
        // return result;
    }
};
// @lc code=end

