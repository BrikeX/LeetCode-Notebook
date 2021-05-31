/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // DP
        vector<vector<int>> dp_table(s.size(), vector<int>(s.size()));

        for (size_t i = 0; i < s.size(); i++)
        {
            dp_table[i][i] = 1;
        }
        
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (size_t j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    dp_table[i][j] = 2 + dp_table[i + 1][j - 1];
                }
                else
                {
                    dp_table[i][j] = max(dp_table[i + 1][j], dp_table[i][j - 1]);
                }
            }
        }
        
        return dp_table[0][s.size() - 1];
    }
};
// @lc code=end

