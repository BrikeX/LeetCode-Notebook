/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // DP，自底向上
        int s1_size = s1.size();

        int s2_size = s2.size();

        vector<vector<int>> dp_table(s1_size + 1, vector<int>(s2_size + 1));
        
        int sum = s1[0] + s2[0];

        for (size_t i = 1; i <= s1_size; i++)
        {
            for (size_t j = 1; j <= s2_size; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp_table[i][j] = dp_table[i - 1][j - 1] + s1[i - 1];
                }
                else
                {
                    dp_table[i][j] = max(dp_table[i - 1][j], dp_table[i][j - 1]);
                }

                if (i == 1 && j < s2_size)
                {
                    sum += s2[j];
                }
            }

            if (i < s1_size)
            {
                sum += s1[i];
            }
        }

        return sum - 2 * dp_table.back().back();

        // // DP，自顶向下
        // memo.resize(s1.size());

        // for (size_t i = 0; i < memo.size(); i++)
        // {
        //     memo[i].resize(s2.size(), -1);
        // }
        
        // return dp(s1, 0, s2, 0);
    }

// private:
//     vector<vector<int>> memo;

//     int dp(string& s1, int i, string& s2, int j)
//     {
//         int sum = 0;

//         if (i == s1.size())
//         {
//             for (; j < s2.size(); j++)
//             {
//                 sum += s2[j];
//             }
            
//             return sum;
//         }
        
//         if (j == s2.size())
//         {
//             for (; i < s1.size(); i++)
//             {
//                 sum += s1[i];
//             }
            
//             return sum;
//         }
        
//         if (memo[i][j] != -1)
//         {
//             return memo[i][j];
//         }
        
//         if (s1[i] == s2[j])
//         {
//             memo[i][j] = dp(s1, i + 1, s2, j + 1);
//         }
//         else
//         {
//             memo[i][j] = min(s1[i] + dp(s1, i + 1, s2, j), 
//                              s2[j] + dp(s1, i, s2, j + 1));
//         }
        
//         return memo[i][j];
//     }
};
// @lc code=end

