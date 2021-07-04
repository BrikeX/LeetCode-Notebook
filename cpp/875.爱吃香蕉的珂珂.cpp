/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // 二分搜索
        int left = 1;

        int right = *max_element(piles.begin(), piles.end());

        int mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (whetherFinish(piles, h, mid))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return left;
    }

    bool whetherFinish(vector<int>& piles, int h, int speed)
    {
        int sum = 0;

        for (auto &&pile : piles)
        {
            sum += (pile - 1) / speed + 1;
        }
        
        return sum <= h;
    }
};
// @lc code=end

