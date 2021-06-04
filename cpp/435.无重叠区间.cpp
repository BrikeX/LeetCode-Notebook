/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 贪心算法
        if (intervals.size() < 2)
        {
            return 0;
        }
        
        return intervals.size() - intervalSchedule(intervals);
    }

    static bool intervals_comparison(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }

    int intervalSchedule(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), intervals_comparison);

        int result = 1;

        int end = intervals[0][1];

        for (size_t i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= end)
            {
                result++;

                end = intervals[i][1];
            }
        }

        return result;
    }
};
// @lc code=end

