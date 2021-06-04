/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> memo;

    unordered_map<char, vector<int>> charToIndex;

    int findRotateSteps(string ring, string key) {
        // DP
        memo.resize(ring.size(), vector<int>(key.size()));

        for (size_t i = 0; i < ring.size(); i++)
        {
            charToIndex[ring[i]].push_back(i);
        }
        
        return dp(ring, 0, key, 0);
    }

    int dp(string& ring, int i, string& key, int j)
    {
        if (j == key.size())
        {
            return 0;
        }
        
        if (memo[i][j])
        {
            return memo[i][j];
        }
        
        int result = INT_MAX;

        for (int k : charToIndex[key[j]])
        {
            int delta = abs(k - i);

            delta = min(delta, (int) ring.size() - delta);

            result = min(result, dp(ring, k, key, j + 1) + 1 + delta);
        }
        
        memo[i][j] = result;

        return result;
    }
};
// @lc code=end

