/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 暴力递归，超时
        if (amount == 0)
        {
            return 0;
        }

        if (amount < 0)
        {
            return -1;
        }
        
        int result = INT_MAX;

        int result_tmp;

        for (size_t i = 0; i < coins.size(); i++)
        {
            result_tmp = coinChange(coins, amount - coins[i]);

            if (result_tmp == -1)
            {
                continue;
            }
            
            result = min(result, result_tmp + 1);
        }
        
        return (result == INT_MAX) ? -1 : result;
    }
};
// @lc code=end

