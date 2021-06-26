/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        // DP，正序
        if (nums.empty())
        {
            return 0;
        }
        
        int nums_size = nums.size();

        if (nums_size == 1)
        {
            return nums.front();
        }
        
        if (nums_size == 2)
        {
            return max(nums[0], nums[1]);
        }
        
        return max(robRange(nums, 0, nums_size - 2), robRange(nums, 1, nums_size - 1));

        // // DP，倒序
        // if (nums.size() == 1)
        // {
        //     return nums.front();
        // }
        
        // return max(dp(nums, 0, nums.size() - 2), dp(nums, 1, nums.size() - 1));
    }

    int robRange(vector<int>& nums, int start, int end)
    {
        int dp_1 = nums[start];

        int dp_2 = max(nums[start], nums[start + 1]);

        int dp_tmp;

        for (size_t i = start + 2; i <= end; i++)
        {
            dp_tmp = dp_2;

            dp_2 = max(nums[i] + dp_1, dp_2);

            dp_1 = dp_tmp;
        }
        
        return dp_2;
    }

    // int dp(vector<int>& nums, int start, int end)
    // {
    //     int dp_i = 0, dp_i_1 = 0, dp_i_2 = 0;

    //     for (int i = end; i >= start; i--)
    //     {
    //         dp_i = max(dp_i_1, nums[i] + dp_i_2);

    //         dp_i_2 = dp_i_1;

    //         dp_i_1 = dp_i;
    //     }
        
    //     return dp_i;
    // }
};
// @lc code=end

