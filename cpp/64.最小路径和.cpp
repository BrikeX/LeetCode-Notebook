/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> memo;

    int minPathSum(vector<vector<int>>& grid) {
        // DP，自底向上
        vector<vector<int>> dp_table(grid.size(), vector<int>(grid[0].size()));

        dp_table[0][0] = grid[0][0];

        for (size_t i = 1; i < grid.size(); i++)
        {
            dp_table[i][0] = dp_table[i - 1][0] + grid[i][0];
        }
        
        for (size_t j = 1; j < grid[0].size(); j++)
        {
            dp_table[0][j] = dp_table[0][j - 1] + grid[0][j];
        }
        
        for (size_t i = 1; i < grid.size(); i++)
        {
            for (size_t j = 1; j < grid[0].size(); j++)
            {
                dp_table[i][j] = min(dp_table[i - 1][j], dp_table[i][j - 1]) + 
                                 grid[i][j];
            }
        }
        
        return dp_table.back().back();

        // // DP，自顶向下
        // memo.resize(grid.size(), vector<int>(grid[0].size(), -1));

        // return dp(grid, grid.size() - 1, grid[0].size() - 1);
    }

    int dp(vector<vector<int>>& grid, int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }
        
        if (i < 0 || j < 0)
        {
            return INT_MAX;
        }
        
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        
        memo[i][j] = min(dp(grid, i - 1, j), dp(grid, i, j - 1)) + grid[i][j];

        return memo[i][j];
    }
};
// @lc code=end

