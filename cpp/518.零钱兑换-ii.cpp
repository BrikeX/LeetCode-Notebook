/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // DP，空间复杂度优化
        vector<int> dp_table(amount + 1);

        dp_table[0] = 1;

        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = 1; j < dp_table.size(); j++)
            {
                if (j - coins[i] >= 0)
                {
                    dp_table[j] = dp_table[j] + dp_table[j - coins[i]];
                }
            }
        }
        
        return dp_table[amount];

        // // DP
        // vector<vector<int>> dp_table(coins.size() + 1, vector<int>(amount + 1));

        // for (size_t i = 0; i < dp_table.size(); i++)
        // {
        //     dp_table[i][0] = 1;
        // }
        
        // for (int i = 1; i < dp_table.size(); i++)
        // {
        //     for (int j = 1; j < dp_table[0].size(); j++)
        //     {
        //         if (j - coins[i - 1] >= 0)
        //         {
        //             dp_table[i][j] = dp_table[i - 1][j] + 
        //                              dp_table[i][j - coins[i - 1]];
        //         }
        //         else
        //         {
        //             dp_table[i][j] = dp_table[i - 1][j];
        //         }
        //     }
        // }
        
        // return dp_table[coins.size()][amount];
    }
};
// @lc code=end

