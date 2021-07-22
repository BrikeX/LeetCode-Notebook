/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // // 分成奇数堆、偶数堆，哪堆大拿哪堆
        // return true;

        // DP
        int piles_size = piles.size();

        vector<vector<int>> dp_table(piles_size, vector<int>(piles_size));

        for (size_t i = 0; i < piles_size; i++)
        {
            dp_table[i][i] = piles[i];
        }
        
        for (int i = piles_size - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < piles_size; j++)
            {
                dp_table[i][j] = max(piles[i] - dp_table[i + 1][j],
                                     piles[j] - dp_table[i][j - 1]);
            }
        }
        
        return dp_table[0][piles_size - 1];

        // DP
        // vector<vector<pair<int, int>>> dp_table(piles.size(), vector<pair<int, int>>(piles.size()));

        // for (int i = 0; i < piles.size(); i++)
        // {
        //     dp_table[i][i].first = piles[i];

        //     dp_table[i][i].second = 0;
        // }

        // int left, right;

        // for (int l = 1; l < piles.size(); l++)
        // {
        //     for (int i = 0; i < piles.size() - l; i++)
        //     {
        //         int j = l + i;

        //         left = piles[i] + dp_table[i + 1][j].second;

        //         right = piles[j] + dp_table[i][j - 1].second;

        //         if (left > right)
        //         {
        //             dp_table[i][j].first = left;

        //             dp_table[i][j].second = dp_table[i + 1][j].first;
        //         }
        //         else
        //         {
        //             dp_table[i][j].first = right;

        //             dp_table[i][j].second = dp_table[i][j - 1].first;
        //         }
        //     }
        // }

        // return dp_table[0].back().first - dp_table[0].back().second;
    }
};
// @lc code=end

