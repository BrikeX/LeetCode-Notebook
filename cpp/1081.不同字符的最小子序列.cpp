/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        // 哈希表
        // 与 316 相同
        string result;

        unordered_map<char, int> memo;

        for (size_t i = 0; i < s.size(); i++)
        {
            memo[s[i]]++;
        }
        
        for (size_t i = 0; i < s.size(); i++)
        {
            memo[s[i]]--;

            if (result.find(s[i]) != string::npos)
            {
                continue;
            }
            
            while (!result.empty() && result.back() > s[i])
            {
                if (!memo[result.back()])
                {
                    break;
                }
                
                result.pop_back();
            }
            
            result.push_back(s[i]);
        }
        
        return result;
    }
};
// @lc code=end

