/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
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

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // DP
        int n = matrix.size();

        if (n == 1)
        {
            return *min_element(matrix[0].begin(), matrix[0].end());
        }
        
        int result = INT_MAX;

        memo.resize(n);

        for (size_t i = 0; i < n; i++)
        {
            memo[i].resize(n);

            for (size_t j = 0; j < n; j++)
            {
                memo[i][j] = INT_MAX;
            }
        }
        
        for (size_t j = 0; j < n; j++)
        {
            result = min(result, dp(matrix, n - 1, j));
        }
        
        return result;
    }
};
// @lc code=end

