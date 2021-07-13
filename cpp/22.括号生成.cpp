/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // 回溯算法
        if (n == 1)
        {
            return {"()"};
        }

        vector<string> result;

        string track;

        backTracking(n, n, track, result);

        return result;
    }

private:
    void backTracking(int left, int right, string& track, vector<string>& result)
    {
        if (right < left)
        {
            return;
        }
        
        if (left < 0 || right < 0)
        {
            return;
        }
        
        if (left == 0 && right == 0)
        {
            result.push_back(track);

            return;
        }
        
        track.push_back('(');

        backTracking(left - 1, right, track, result);

        track.pop_back();

        track.push_back(')');

        backTracking(left, right - 1, track, result);

        track.pop_back();
    }
};
// @lc code=end

