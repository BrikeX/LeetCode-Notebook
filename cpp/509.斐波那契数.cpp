/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        // 暴力递归
        if (n == 0)
        {
            return 0;
        }
        
        if (n == 1 || n == 2)
        {
            return 1;
        }
        
        return (fib(n-1) + fib(n-2));
    }
};
// @lc code=end

