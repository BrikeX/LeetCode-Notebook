/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        // 单调栈
        // 与 316 相同
        string result;

        unordered_map<char, int> memo;

        for (auto &&c : s)
        {
            ++memo[c];
        }

        for (auto &&c : s)
        {
            --memo[c];

            if (result.find(c) != string::npos)
            {
                continue;
            }
            
            while (!result.empty() && result.back() > c)
            {
                if (!memo[result.back()])
                {
                    break;
                }
                
                result.pop_back();
            }
            
            result.push_back(c);
        }
        
        return result;
    }
};
// @lc code=end

