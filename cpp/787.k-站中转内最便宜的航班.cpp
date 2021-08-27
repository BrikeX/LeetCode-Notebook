/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // DP
        vector<vector<int>> dp_table(k + 2, vector<int>(n, INF));

        dp_table[0][src] = 0;

        for (int i = 1; i <= k + 1; i++)
        {
            for (auto &&flight : flights)
            {
                int from = flight[0];

                int to = flight[1];

                int cost = flight[2];

                dp_table[i][to] = min(dp_table[i][to], 
                                      dp_table[i - 1][from] + cost);
            }
        }
        
        int result = INF;

        for (int i = 1; i <= k + 1; i++)
        {
            result = min(result, dp_table[i][dst]);
        }
        
        return (result == INF ? -1 : result);
    }

private:
    const int INF = 10000 * 101 + 1;
};
// @lc code=end

