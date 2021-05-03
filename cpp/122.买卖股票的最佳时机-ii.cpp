/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // DP
        int profit_0 = 0, profit_1 = INT_MIN;

        int profit_tmp;

        for (size_t i = 0; i < prices.size(); i++)
        {
            profit_tmp = profit_0;

            profit_0 = max(profit_0, profit_1 + prices[i]);

            profit_1 = max(profit_1, profit_tmp - prices[i]);
        }
        
        return profit_0;
    }
};
// @lc code=end

