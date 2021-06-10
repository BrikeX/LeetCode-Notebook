/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        for (auto &&c : s)
        {
            if (c == '{' || c == '[' || c == '(')
            {
                brackets.push(c);
            }
            else
            {
                if (!brackets.empty() && leftBracket(c) == brackets.top())
                {
                    brackets.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        
        return brackets.empty();
    }

    char leftBracket(char c)
    {
        if (c == '}')
        {
            return '{';
        }
        else if (c == ']')
        {
            return '[';
        }
        else
        {
            return '(';
        }
    }
};
// @lc code=end

