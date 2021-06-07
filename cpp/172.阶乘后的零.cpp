/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;

        for (int d = n; d / 5 > 0; d /= 5)
        {
            result += d / 5;
        }
        
        return result;
    }
};
// @lc code=end

