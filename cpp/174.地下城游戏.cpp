/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // DP，自顶向下
        memo.resize(dungeon.size(), vector<int>(dungeon[0].size(), -1));

        return dp(dungeon, 0, 0);
    }

private:
    vector<vector<int>> memo;

    int dp(vector<vector<int>>& dungeon, int i, int j)
    {
        if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1)
        {
            return dungeon[i][j] >= 0 ? 1 : -dungeon[i][j] + 1;
        }
        
        if (i == dungeon.size() || j == dungeon[0].size())
        {
            return INT_MAX;
        }
        
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        int hp = min(dp(dungeon, i + 1, j), dp(dungeon, i, j + 1)) -
                 dungeon[i][j];
        
        memo[i][j] = hp <= 0 ? 1 : hp;

        return memo[i][j];
    }
};
// @lc code=end

