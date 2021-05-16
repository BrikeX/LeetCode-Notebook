/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
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

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), intervals_comparison);

        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= result.back()[1])
            {
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};
// @lc code=end

