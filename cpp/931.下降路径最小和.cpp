/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // DP，自底向上，空间优化
        int n = matrix.size();

        if (n == 1)
        {
            return matrix[0][0];
        }

        vector<vector<int>> dp_table(2, vector<int>(matrix[0].size()));

        dp_table[0] = matrix[0];
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    dp_table[1][j] = matrix[i][j] + min(dp_table[0][j], dp_table[0][j + 1]);
                }
                else if (j == n - 1)
                {
                    dp_table[1][j] = matrix[i][j] + min(dp_table[0][j], dp_table[0][j - 1]);
                }
                else
                {
                    dp_table[1][j] = matrix[i][j] + min(dp_table[0][j], min(dp_table[0][j - 1], dp_table[0][j + 1]));
                }
            }

            dp_table[0] = dp_table[1];
        }

        return *min_element(dp_table[1].begin(), dp_table[1].end());

        // // DP，自底向上
        // int n = matrix.size();

        // if (n == 1)
        // {
        //     return matrix[0][0];
        // }

        // vector<vector<int>> dp_table(matrix.size(), vector<int>(matrix[0].size()));

        // dp_table[0] = matrix[0];
        
        // for (int i = 1; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (j == 0)
        //         {
        //             dp_table[i][j] = matrix[i][j] + min(dp_table[i - 1][j], dp_table[i - 1][j + 1]);
        //         }
        //         else if (j == n - 1)
        //         {
        //             dp_table[i][j] = matrix[i][j] + min(dp_table[i - 1][j], dp_table[i - 1][j - 1]);
        //         }
        //         else
        //         {
        //             dp_table[i][j] = matrix[i][j] + min(dp_table[i - 1][j], min(dp_table[i - 1][j - 1], dp_table[i - 1][j + 1]));
        //         }
        //     }
        // }
        
        // return *min_element(dp_table[n - 1].begin(), dp_table[n - 1].end());

        // // DP，自顶向下
        // int n = matrix.size();

        // if (n == 1)
        // {
        //     return *min_element(matrix[0].begin(), matrix[0].end());
        // }
        
        // int result = INT_MAX;

        // memo.resize(n);

        // for (size_t i = 0; i < n; i++)
        // {
        //     memo[i].resize(n);

        //     for (size_t j = 0; j < n; j++)
        //     {
        //         memo[i][j] = INT_MAX;
        //     }
        // }
        
        // for (size_t j = 0; j < n; j++)
        // {
        //     result = min(result, dp(matrix, n - 1, j));
        // }
        
        // return result;
    }

private:
    vector<vector<int>> memo;

    int dp(vector<vector<int>>& matrix, int i, int j)
    {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
        {
            return INT_MAX;
        }
        
        if (i == 0)
        {
            return matrix[i][j];
        }
        
        if (memo[i][j] != INT_MAX)
        {
            return memo[i][j];
        }

        memo[i][j] = matrix[i][j] + 
                     min(dp(matrix, i-1, j-1), min(dp(matrix, i-1, j), dp(matrix, i-1, j+1)));
        
        return memo[i][j];
    }
};
// @lc code=end

