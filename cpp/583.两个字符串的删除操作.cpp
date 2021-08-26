/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // DP
        int lcs_size = longestCommonSubsequence(word1, word2);

        return word1.size() - lcs_size + word2.size() - lcs_size;
    }

    int longestCommonSubsequence(string& text1, string& text2) {
        vector<vector<int>> dp_table(text1.size() + 1, vector<int>(text2.size() + 1));
        
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
        
        return dp_table.back().back();
    }
};
// @lc code=end

