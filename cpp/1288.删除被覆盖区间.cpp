/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start
class Solution {
public:
    static bool intervals_comparison(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] == b[0])
        {
            return b[1] < a[1];
        }
        
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {        
        sort(intervals.begin(), intervals.end(), intervals_comparison);

        int left = intervals[0][0];

        int right = intervals[0][1];

        int result = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (right >= intervals[i][1])
            {
                result++;
            }
            else
            {
                right = intervals[i][1];
            }
        }
        
        return intervals.size() - result;
    }
};
// @lc code=end

