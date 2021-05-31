/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // DP
        vector<vector<int>> dp_table(word1.size() + 1);

        for (size_t i = 0; i < dp_table.size(); i++)
        {
            dp_table[i].resize(word2.size() + 1);
        }
        
        for (size_t i = 1; i < dp_table.size(); i++)
        {
            dp_table[i][0] = i;
        }
        
        for (size_t j = 1; j < dp_table[0].size(); j++)
        {
            dp_table[0][j] = j;
        }
        
        for (size_t i = 1; i < dp_table.size(); i++)
        {
            for (size_t j = 1; j < dp_table[0].size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp_table[i][j] = dp_table[i - 1][j - 1];
                }
                else
                {
                    dp_table[i][j] = min(dp_table[i - 1][j] + 1,
                                         min(dp_table[i][j - 1] + 1,
                                             dp_table[i - 1][j - 1] + 1));
                }
            }
        }
        
        return dp_table[word1.size()][word2.size()];
    }
};
// @lc code=end

