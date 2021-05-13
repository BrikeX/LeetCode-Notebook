/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        // DP，自顶向下
        vector<int> memo(nums.size(), -1);

        return dp(nums, memo, 0);
    }

    int dp(vector<int>& nums, vector<int>& memo, int start)
    {
        if (start >= nums.size())
        {
            return 0;
        }
        
        if (memo[start] != -1)
        {
            return memo[start];
        }
        else
        {
            int result = max(dp(nums, memo, start + 1),
                             dp(nums, memo, start + 2) + nums[start]);

            memo[start] = result;

            return result;
        }
    }
};
// @lc code=end

