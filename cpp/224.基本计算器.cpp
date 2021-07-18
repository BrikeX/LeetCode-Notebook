/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        // 递归算法
        return computer(s);
    }

private:
    int index = 0;

    int computer(string &s)
    {
        stack<int> nums_stack;

        int num = 0;

        char sign = '+';

        while (index < s.size())
        {
            char c = s[index++];

            if (isdigit(c))
            {
                num = 10 * num + (c - '0');
            }

            if (c == '(')
            {
                num = computer(s);
            }
            
            if ((!isdigit(c) && c != ' ') || index == s.size())
            {
                switch (sign)
                {
                case '+':
                    nums_stack.push(num);
                    
                    break;

                case '-':
                    nums_stack.push(-num);
                    
                    break;
                }

                sign = c;

                num = 0;
            }

            if (c == ')')
            {
                break;
            }
        }
        
        int result = 0;

        while (!nums_stack.empty())
        {
            result += nums_stack.top();

            nums_stack.pop();
        }
        
        return result;
    }
};
// @lc code=end

