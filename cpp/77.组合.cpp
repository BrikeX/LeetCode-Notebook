/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // 回溯算法
        vector<vector<int>> result;

        if (n <= 0 || k <= 0)
        {
            return result;
        }
        
        vector<int> track;

        backTracking(n, k, 1, track, result);

        return result;
    }

private:
    void backTracking(int n, int k, int start, vector<int>& track, vector<vector<int>>& result)
    {
        if (track.size() == k)
        {
            result.push_back(track);

            return;
        }
        
        for (int i = start; i <= n; i++)
        {
            track.push_back(i);

            backTracking(n, k, i + 1, track, result);

            track.pop_back();
        }
    }
};
// @lc code=end

