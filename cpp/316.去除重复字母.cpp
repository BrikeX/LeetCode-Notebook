/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 单调栈
        // 与 1081 相同
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

