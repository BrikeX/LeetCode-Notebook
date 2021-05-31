/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // DP，空间复杂度优化
        if (nums.size() == 1)
        {
            return nums.front();
        }

        int dp_0 = nums[0], dp_1 = 0;

        int result = dp_0;

        for (size_t i = 1; i < nums.size(); i++)
        {
            dp_1 = max(nums[i], dp_0 + nums[i]);

            dp_0 = dp_1;

            result = max(result, dp_1);
        }
        
        return result;

        // // DP
        // if (nums.size() == 1)
        // {
        //     return nums.front();
        // }
        
        // vector<int> dp_table(nums.size());

        // dp_table[0] = nums[0];

        // for (size_t i = 1; i < nums.size(); i++)
        // {
        //     dp_table[i] = max(nums[i], dp_table[i - 1] + nums[i]);
        // }
        
        // return *max_element(dp_table.begin(), dp_table.end());
    }
};
// @lc code=end

