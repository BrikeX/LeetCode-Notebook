/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    // DP，自底向上
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp_table(text1.size() + 1);

        for (size_t i = 0; i < dp_table.size(); i++)
        {
            dp_table[i].resize(text2.size() + 1);
        }
        
        for (size_t i = 1; i < dp_table.size(); i++)
        {
            for (size_t j = 1; j < dp_table[0].size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp_table[i][j] = 1 + dp_table[i - 1][j - 1];
                }
                else
                {
                    dp_table[i][j] = max(dp_table[i][j - 1], dp_table[i - 1][j]);
                }
            }
        }
        
        return dp_table[text1.size()][text2.size()];
    }
    
    // // DP，自顶向下
    // vector<vector<int>> memo;

    // int longestCommonSubsequence(string text1, string text2) {
    //     memo.resize(text1.size());

    //     for (size_t i = 0; i < memo.size(); i++)
    //     {
    //         memo[i].resize(text2.size(), -1);
    //     }
        
    //     return dp(text1, 0, text2, 0);
    // }

    // int dp(string& text1, int i, string& text2, int j)
    // {
    //     if (i == text1.size() || j == text2.size())
    //     {
    //         return 0;
    //     }
        
    //     if (memo[i][j] != -1)
    //     {
    //         return memo[i][j];
    //     }
        
    //     if (text1[i] == text2[j])
    //     {
    //         memo[i][j] = 1 + dp(text1, i + 1, text2, j + 1);
    //     }
    //     else
    //     {
    //         memo[i][j] = max(dp(text1, i + 1, text2, j), dp(text1, i, text2, j + 1));
    //     }
        
    //     return memo[i][j];
    // }
};
// @lc code=end

