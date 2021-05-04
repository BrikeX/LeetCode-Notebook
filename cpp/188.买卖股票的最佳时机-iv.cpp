/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // DP
        int day_max = prices.size();
        
        if (day_max < 2 || k == 0)
        {
            return 0;
        }

        int k_max = (k < day_max/2) ? k : day_max/2;

        int profit[day_max][k_max+1][2];

        // profit[i][k][0] = max(profit[i-1][k][0], profit[i-1][k][1] + prices[i])
        // profit[i][k][1] = max(profit[i-1][k][1], profit[i-1][k-1][0] - prices[i])

        // profit[0][k][0] = max(profit[-1][k][0], profit[-1][k][1] + prices[0])
        //                 = max(0, -inf + prices[0])
        //                 = 0
        // profit[0][k][1] = max(profit[-1][k][1], profit[-1][k-1][0] - prices[0])
        //                 = max(-inf, 0 - prices[0])
        //                 = -prices[0]

        for (size_t i = 0; i < prices.size(); i++)
        {
            for (size_t k = k_max; k > 0; k--)
            {                
                if (i == 0)
                {
                    profit[i][k][0] = 0;

                    profit[i][k][1] = -prices[i];

                    continue;
                }
                
                if (k == 1)
                {
                    profit[i-1][k-1][0] = 0;

                    profit[i-1][k-1][1] = INT_MIN;
                }
                
                profit[i][k][0] = max(profit[i-1][k][0], profit[i-1][k][1] + prices[i]);
        
                profit[i][k][1] = max(profit[i-1][k][1], profit[i-1][k-1][0] - prices[i]);
            }
        }
        
        return profit[day_max-1][k_max][0];
    }
};
// @lc code=end

