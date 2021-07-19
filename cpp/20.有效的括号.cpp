/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2)
        {
            return false;
        }
        
        unordered_map<char, char> bracket_map({
            {')', '('},
            {']', '['},
            {'}', '{'}});
        
        stack<char> brackets;

        for (auto &&c : s)
        {
            if (bracket_map.count(c))
            {
                if (brackets.empty() || brackets.top() != bracket_map[c])
                {
                    return false;
                }
                
                brackets.pop();
            }
            else
            {
                brackets.push(c);
            }
        }
        
        return brackets.empty();
    }
};
// @lc code=end

