/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    static bool intervals_comparison(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        // 贪心算法
        if (points.size() < 2)
        {
            return points.size();
        }
        
        sort(points.begin(), points.end(), intervals_comparison);

        int result = 1;

        int end = points[0][1];

        for (size_t i = 0; i < points.size(); i++)
        {
            if (points[i][0] > end)
            {
                result++;

                end = points[i][1];
            }
        }
        
        return result;
    }
};
// @lc code=end

