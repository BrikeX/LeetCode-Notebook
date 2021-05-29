/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 哈希表
        // 与 1081 相同
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

