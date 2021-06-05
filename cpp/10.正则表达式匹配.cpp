/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, int> memo;

    bool isMatch(string s, string p) {
        // DP
        return dp(s, 0, p, 0);
    }

    bool dp(string& s, int i, string& p, int j)
    {
        if (j == p.size())
        {
            return i == s.size();
        }
        
        if (i == s.size())
        {
            if ((p.size() - j) % 2)
            {
                return false;
            }
            
            for (; j + 1 < p.size(); j += 2)
            {
                if (p[j + 1] != '*')
                {
                    return false;
                }
            }
            
            return true;
        }

        stringstream ss;

        ss << i;

        string key = ss.str();

        key += ",";

        ss.clear();

        ss.str("");

        ss << j;

        key += ss.str();

        if (memo.count(key))
        {
            return memo[key];
        }
        
        bool result = false;

        if (s[i] == p[j] || p[j] == '.')
        {
            if (j + 1 < p.size() && p[j + 1] == '*')
            {
                result = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
            }
            else
            {
                result = dp(s, i + 1, p, j + 1);
            }
        }
        else
        {
            if (j + 1 < p.size() && p[j + 1] == '*')
            {
                result = dp(s, i, p, j + 2);
            }
            else
            {
                result = false;
            }
        }
        
        memo[key] = result;

        return result;
    }
};
// @lc code=end

