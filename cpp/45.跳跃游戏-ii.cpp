/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    vector<int> memo;

    int jump(vector<int>& nums) {
        // DP
        memo.resize(nums.size(), nums.size());

        return dp(nums, 0);
    }

    int dp(vector<int>& nums, int p)
    {
        if (p >= nums.size() - 1)
        {
            return 0;
        }
        
        if (memo[p] != nums.size())
        {
            return memo[p];
        }
        
        for (size_t i = 1; i <= nums[p]; i++)
        {
            memo[p] = min(memo[p], dp(nums, p + i) + 1);
        }
        
        return memo[p];
    }
};
// @lc code=end

