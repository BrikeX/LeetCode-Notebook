/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 贪心算法
        int furthest = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            furthest = max(furthest, i + nums[i]);

            if (furthest <= i)
            {
                return false;
            }
        }
        
        return furthest >= nums.size() - 1;
    }
};
// @lc code=end

