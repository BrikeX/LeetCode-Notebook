/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, int> memo;

    int dp(vector<int>& nums, int start, int rest)
    {
        if (start == nums.size())
        {
            if (rest == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        stringstream ss;

        ss << start;

        string str = ss.str();

        str += ",";

        ss.clear();

        ss.str("");

        ss << rest;

        str += ss.str();

        auto it = memo.find(str);

        if (it != memo.end())
        {
            return it->second;
        }
        
        int result = dp(nums, start + 1, rest - nums[start]) + 
                     dp(nums, start + 1, rest + nums[start]);

        memo.emplace(str, result);

        return result;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // // DP
        // return dp(nums, 0, target);

        // DP，背包问题
        int sum = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        
        if (sum < target || (sum + target) % 2)
        {
            return 0;
        }
        
        return subsets(nums, (sum + target) / 2);
    }

    int subsets(vector<int>& nums, int sum) 
    {
        // vector<vector<int>> dp_table(nums.size() + 1, vector<int>(sum + 1));

        // for (size_t i = 0; i < dp_table.size(); i++)
        // {
        //     dp_table[i][0] = 1;
        // }
        
        // for (int i = 1; i < dp_table.size(); i++)
        // {
        //     for (int j = 0; j < dp_table[0].size(); j++)
        //     {
        //         if (j >= nums[i - 1])
        //         {
        //             dp_table[i][j] = dp_table[i - 1][j] + 
        //                              dp_table[i - 1][j - nums[i - 1]];
        //         }
        //         else
        //         {
        //             dp_table[i][j] = dp_table[i - 1][j];
        //         }
        //     }
        // }
        
        // return dp_table[nums.size()][sum];

        vector<int> dp_table(sum + 1);

        dp_table[0] = 1;

        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = sum; j >= 0; j--)
            {
                if (j >= nums[i - 1])
                {
                    dp_table[j] = dp_table[j] + dp_table[j - nums[i - 1]];
                }
                else
                {
                    dp_table[j] = dp_table[j];
                }
            }
        }
        
        return dp_table[sum];
    }
};
// @lc code=end

