/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // DP，空间复杂度优化
        int sum = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        
        if (sum % 2)
        {
            return false;
        }
        
        sum /= 2;

        vector<bool> dp_table(sum + 1, false);

        dp_table[0] = true;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = sum; j >= 0; j--)
            {
                if (j - nums[i] >= 0)
                {
                    dp_table[j] = dp_table[j] || dp_table[j - nums[i]];
                }
            }
        }
        
        return dp_table[sum];

        // // DP
        // int sum = 0;

        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     sum += nums[i];
        // }
        
        // if (sum % 2)
        // {
        //     return false;
        // }
        
        // sum /= 2;

        // vector<vector<bool>> dp_table(nums.size() + 1, vector<bool>(sum + 1, false));

        // for (size_t i = 0; i < dp_table.size(); i++)
        // {
        //     dp_table[i][0] = true;
        // }
        
        // for (int i = 1; i < dp_table.size(); i++)
        // {
        //     for (int j = 1; j < dp_table[0].size(); j++)
        //     {
        //         if (j - nums[i - 1] < 0)
        //         {
        //             dp_table[i][j] = dp_table[i - 1][j];
        //         }
        //         else
        //         {
        //             dp_table[i][j] = dp_table[i - 1][j] || dp_table[i - 1][j - nums[i - 1]];
        //         }
        //     }
        // }
        
        // return dp_table[nums.size()][sum];
    }
};
// @lc code=end

