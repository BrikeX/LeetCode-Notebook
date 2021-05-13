/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        // DP
        if (nums.size() == 1)
        {
            return nums.front();
        }
        
        return max(dp(nums, 0, nums.size() - 2), dp(nums, 1, nums.size() - 1));
    }

    int dp(vector<int>& nums, int start, int end)
    {
        int dp_i = 0, dp_i_1 = 0, dp_i_2 = 0;

        for (int i = end; i >= start; i--)
        {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);

            dp_i_2 = dp_i_1;

            dp_i_1 = dp_i;
        }
        
        return dp_i;
    }
};
// @lc code=end

