/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // 二分搜索
        int left = -1;

        int right = 0;

        for (auto &&weight : weights)
        {
            left = max(left, weight);

            right += weight;
        }

        int mid;
        
        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (whetherFinish(weights, days, mid))
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

    bool whetherFinish(vector<int>& weights, int days, int w)
    {
        int i = 0;

        int w_max;

        for (size_t day = 0; day < days; day++)
        {
            w_max = w;

            while ((w_max -= weights[i]) >= 0)
            {
                i++;

                if (i == weights.size())
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
// @lc code=end

