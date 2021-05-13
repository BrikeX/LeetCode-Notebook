/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        // DP，自底向上，内存优化
        int dp_i = 0, dp_i_1 = 0, dp_i_2 = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);

            dp_i_2 = dp_i_1;

            dp_i_1 = dp_i;
        }
        
        return dp_i;
        
        // // DP，自底向上
        // vector<int> result(nums.size() + 2, 0);

        // for (int i = nums.size() - 1; i >= 0; i--)
        // {
        //     result[i] = max(result[i + 1], nums[i] + result[i + 2]);
        // }
        
        // return result[0];

        // // DP，自顶向下
        // vector<int> memo(nums.size(), -1);

        // return dp(nums, memo, 0);
    }

    // int dp(vector<int>& nums, vector<int>& memo, int start)
    // {
    //     if (start >= nums.size())
    //     {
    //         return 0;
    //     }
        
    //     if (memo[start] != -1)
    //     {
    //         return memo[start];
    //     }
    //     else
    //     {
    //         int result = max(dp(nums, memo, start + 1),
    //                          dp(nums, memo, start + 2) + nums[start]);

    //         memo[start] = result;

    //         return result;
    //     }
    // }
};
// @lc code=end

