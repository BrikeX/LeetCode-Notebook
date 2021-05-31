/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> memo;

    int minimumDeleteSum(string s1, string s2) {
        // DP
        memo.resize(s1.size());

        for (size_t i = 0; i < memo.size(); i++)
        {
            memo[i].resize(s2.size(), -1);
        }
        
        return dp(s1, 0, s2, 0);
    }

    int dp(string& s1, int i, string& s2, int j)
    {
        int sum = 0;

        if (i == s1.size())
        {
            for (; j < s2.size(); j++)
            {
                sum += s2[j];
            }
            
            return sum;
        }
        
        if (j == s2.size())
        {
            for (; i < s1.size(); i++)
            {
                sum += s1[i];
            }
            
            return sum;
        }
        
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        
        if (s1[i] == s2[j])
        {
            memo[i][j] = dp(s1, i + 1, s2, j + 1);
        }
        else
        {
            memo[i][j] = min(s1[i] + dp(s1, i + 1, s2, j), 
                             s2[j] + dp(s1, i, s2, j + 1));
        }
        
        return memo[i][j];
    }
};
// @lc code=end

