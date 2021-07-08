/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */

// @lc code=start
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        // DP，自底向上
        int ring_size = ring.size(), key_size = key.size();

        unordered_map<char, vector<int>> charToIndex;

        for (int i = 0; i < ring_size; i++)
        {
            charToIndex[ring[i]].push_back(i);
        }
        
        vector<vector<int>> dp_table(key_size, vector<int>(ring_size, INT_MAX));

        for (auto &&i : charToIndex[key[0]])
        {
            dp_table[0][i] = min(i, ring_size - i) + 1;
        }
        
        for (int i = 1; i < key_size; i++)
        {
            for (auto &&j : charToIndex[key[i]])
            {
                for (auto &&k : charToIndex[key[i - 1]])
                {
                    dp_table[i][j] = min(dp_table[i][j], dp_table[i - 1][k] + min(abs(j - k), ring_size - abs(j - k)) + 1);
                }
            }
        }
        
        return *min_element(dp_table.back().begin(), dp_table.back().end());
        
        // // DP，自顶向下
        // memo.resize(ring.size(), vector<int>(key.size()));

        // for (size_t i = 0; i < ring.size(); i++)
        // {
        //     charToIndex[ring[i]].push_back(i);
        // }
        
        // return dp(ring, 0, key, 0);
    }

private:
    // vector<vector<int>> memo;

    // unordered_map<char, vector<int>> charToIndex;

    // int dp(string& ring, int i, string& key, int j)
    // {
    //     if (j == key.size())
    //     {
    //         return 0;
    //     }
        
    //     if (memo[i][j])
    //     {
    //         return memo[i][j];
    //     }
        
    //     int result = INT_MAX;

    //     for (int k : charToIndex[key[j]])
    //     {
    //         int delta = abs(k - i);

    //         delta = min(delta, (int) ring.size() - delta);

    //         result = min(result, dp(ring, k, key, j + 1) + 1 + delta);
    //     }
        
    //     memo[i][j] = result;

    //     return result;
    // }
};
// @lc code=end

