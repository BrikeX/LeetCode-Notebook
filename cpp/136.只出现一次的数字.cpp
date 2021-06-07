/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 位操作
        int result = 0;

        for (int num : nums)
        {
            result ^= num;
        }
        
        return result;
    }
};
// @lc code=end

