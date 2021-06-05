/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        // DP
        vector<vector<int>> dp_table(s.size(), vector<int>(s.size()));

        for (int i = s.size() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    dp_table[i][j] = dp_table[i + 1][j - 1];
                }
                else
                {
                    dp_table[i][j] = min(dp_table[i + 1][j], dp_table[i][j - 1]) + 1;
                }
            }
        }
        
        return dp_table[0].back();
    }
};
// @lc code=end

