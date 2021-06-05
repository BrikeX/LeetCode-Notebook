/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // DP
        vector<int> points(nums.size() + 2);

        for (size_t i = 0; i < points.size(); i++)
        {
            if (i == 0 || i == points.size() - 1)
            {
                points[i] = 1;
            }
            else
            {
                points[i] = nums[i - 1];
            }
        }
        
        vector<vector<int>> dp_table(points.size(), vector<int>(points.size()));

        for (int i = points.size() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                for (int k = i + 1; k < j; k++)
                {
                    dp_table[i][j] = max(dp_table[i][j], 
                                         dp_table[i][k] + dp_table[k][j] + points[i] * points[j] * points[k]);
                }
            }
        }
        
        return dp_table[0].back();
    }
};
// @lc code=end

