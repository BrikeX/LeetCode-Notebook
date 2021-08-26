/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    // int memo(vector<int>& coins, unordered_map<int, int>& hash_table, int amount)
    // {
    //     if (amount < 0)
    //     {
    //         return -1;
    //     }
        
    //     auto it = hash_table.find(amount);

    //     if (it != hash_table.end())
    //     {
    //         return it->second;
    //     }
    //     else
    //     {
    //         int result = INT_MAX;

    //         int result_tmp;

    //         for (size_t i = 0; i < coins.size(); i++)
    //         {
    //             result_tmp = memo(coins, hash_table, amount - coins[i]);

    //             if (result_tmp == -1)
    //             {
    //                 continue;
    //             }
                
    //             result = min(result, result_tmp + 1);
    //         }

    //         hash_table[amount] = (result == INT_MAX) ? -1 : result;

    //         return hash_table[amount];      
    //     }
    // }

    int coinChange(vector<int>& coins, int amount) {
        // DP
        if (amount == 0)
        {
            return 0;
        }
        
        vector<int> dp_table(amount+1, amount+1);

        dp_table[0] = 0;

        // 完全背包问题
        for (auto &&coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp_table[i] = min(dp_table[i], dp_table[i - coin] + 1);
            }
        }
        
        // for (int i = 0; i < dp_table.size(); i++)
        // {
        //     for (int j = 0; j < coins.size(); j++)
        //     {
        //         if (i - coins[j] < 0)
        //         {
        //             continue;
        //         }
                
        //         dp_table[i] = min(dp_table[i], dp_table[i - coins[j]] + 1);
        //     }
        // }
        
        return (dp_table[amount] == amount + 1) ? -1 : dp_table[amount];

        // // 哈希表
        // if (amount == 0)
        // {
        //     return 0;
        // }
        
        // unordered_map<int, int> hash_table = {{0, 0}};

        // return memo(coins, hash_table, amount);

        // // 暴力递归，超时
        // if (amount == 0)
        // {
        //     return 0;
        // }

        // if (amount < 0)
        // {
        //     return -1;
        // }
        
        // int result = INT_MAX;

        // int result_tmp;

        // for (size_t i = 0; i < coins.size(); i++)
        // {
        //     result_tmp = coinChange(coins, amount - coins[i]);

        //     if (result_tmp == -1)
        //     {
        //         continue;
        //     }
            
        //     result = min(result, result_tmp + 1);
        // }
        
        // return (result == INT_MAX) ? -1 : result;
    }
};
// @lc code=end

