/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // DP
        vector<vector<pair<int, int>>> dp_table(piles.size(), vector<pair<int, int>>(piles.size()));

        for (int i = 0; i < piles.size(); i++)
        {
            dp_table[i][i].first = piles[i];

            dp_table[i][i].second = 0;
        }

        int left, right;

        for (int l = 2; l <= piles.size(); l++)
        {
            for (int i = 0; i <= piles.size() - l; i++)
            {
                int j = l + i - 1;

                left = piles[i] + dp_table[i + 1][j].second;

                right = piles[j] + dp_table[i][j - 1].second;

                if (left > right)
                {
                    dp_table[i][j].first = left;

                    dp_table[i][j].second = dp_table[i + 1][j].first;
                }
                else
                {
                    dp_table[i][j].first = right;

                    dp_table[i][j].second = dp_table[i][j - 1].first;
                }
            }
        }

        return dp_table[0].back().first - dp_table[0].back().second;
    }
};
// @lc code=end

