/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

// @lc code=start
class Solution {
public:
    int preimageSizeFZF(int k) {
        // 二分搜索
        long left = leftBoundary(k);

        // if (left == -1)
        // {
        //     return 0;
        // }
        
        long right = rightBoundary(k);

        // if (right == -1)
        // {
        //     return 0;
        // }

        return right - left + 1;
    }

    long trailingZeroes(long n) 
    {
        long result = 0;

        for (long d = n; d / 5 > 0; d /= 5)
        {
            result += d / 5;
        }
        
        return result;
    }

    long leftBoundary(int target)
    {
        long left = 0, right = LONG_MAX - 1;

        long mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (trailingZeroes(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        // if (left == LONG_MAX || trailingZeroes(mid) != target)
        // {
        //     return -1;
        // }
        
        return left;
    }

    long rightBoundary(int target)
    {
        long left = 0, right = LONG_MAX - 1;

        long mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (trailingZeroes(mid) <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // if (right < 0 || trailingZeroes(right) != target)
        // {
        //     return -1;
        // }
        
        return right;
    }
};
// @lc code=end

