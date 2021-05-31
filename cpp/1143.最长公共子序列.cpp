/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    // DP，自顶向下
    vector<vector<int>> memo;

    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size());

        for (size_t i = 0; i < memo.size(); i++)
        {
            memo[i].resize(text2.size(), -1);
        }
        
        return dp(text1, 0, text2, 0);
    }

    int dp(string& text1, int i, string& text2, int j)
    {
        if (i == text1.size() || j == text2.size())
        {
            return 0;
        }
        
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        
        if (text1[i] == text2[j])
        {
            memo[i][j] = 1 + dp(text1, i + 1, text2, j + 1);
        }
        else
        {
            memo[i][j] = max(dp(text1, i + 1, text2, j), dp(text1, i, text2, j + 1));
        }
        
        return memo[i][j];
    }
};
// @lc code=end

