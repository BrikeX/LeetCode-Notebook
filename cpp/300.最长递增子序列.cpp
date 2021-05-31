/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // DP
        vector<int> dp_table(nums.size(), 1);

        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp_table[i] = max(dp_table[i], dp_table[j] + 1);
                }
            }
        }
        
        return *max_element(dp_table.begin(), dp_table.end());

        // // 二分搜索
        // vector<int> top(nums.size());

        // int piles = 0;

        // int left, right, mid;

        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     left = 0;

        //     right = piles;

        //     while (left < right)
        //     {
        //         mid = left + (right - left) / 2;

        //         if (top[mid] >= nums[i])
        //         {
        //             right = mid;
        //         }
        //         else
        //         {
        //             left = mid + 1;
        //         }
        //     }
            
        //     if (left == piles)
        //     {
        //         piles++;
        //     }
            
        //     top[left] = nums[i];
        // }

        // return piles;
    }
};
// @lc code=end

