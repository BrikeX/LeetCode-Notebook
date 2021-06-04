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
        // DP
        memo.resize(grid.size(), vector<int>(grid[0].size(), -1));

        return dp(grid, grid.size() - 1, grid[0].size() - 1);
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

