/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // DP，空间复杂度优化
        vector<int> dp_table(s.size(), 1);

        for (int i = s.size() - 2; i >= 0; i--)
        {
            int pre = 0;

            for (size_t j = i + 1; j < s.size(); j++)
            {
                int tmp = dp_table[j];

                if (s[i] == s[j])
                {
                    dp_table[j] = pre + 2;
                }
                else
                {
                    dp_table[j] = max(dp_table[j], dp_table[j - 1]);
                }
                
                pre = tmp;
            }
        }
        
        return dp_table.back();

        // // DP
        // vector<vector<int>> dp_table(s.size(), vector<int>(s.size()));

        // for (size_t i = 0; i < s.size(); i++)
        // {
        //     dp_table[i][i] = 1;
        // }
        
        // for (int i = s.size() - 1; i >= 0; i--)
        // {
        //     for (size_t j = i + 1; j < s.size(); j++)
        //     {
        //         if (s[i] == s[j])
        //         {
        //             dp_table[i][j] = 2 + dp_table[i + 1][j - 1];
        //         }
        //         else
        //         {
        //             dp_table[i][j] = max(dp_table[i + 1][j], dp_table[i][j - 1]);
        //         }
        //     }
        // }
        
        // return dp_table[0][s.size() - 1];
    }
};
// @lc code=end

