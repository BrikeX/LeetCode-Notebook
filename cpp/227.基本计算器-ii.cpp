/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        // stack
        stack<int> nums_stack;

        int num = 0;

        char sign = '+';

        for (auto it = s.begin(); it != s.end(); it++)
        {
            char c = *it;

            if (isdigit(c))
            {
                num = 10 * num + (c - '0');
            }
            
            if ((!isdigit(c) && c != ' ') || it == s.end() - 1)
            {
                switch (sign)
                {
                case '+':
                    nums_stack.push(num);

                    break;
                
                case '-':
                    nums_stack.push(-num);

                    break;
                
                case '*':
                    nums_stack.top() *= num;

                    break;

                case '/':
                    nums_stack.top() /= num;

                    break;
                }

                sign = c;

                num = 0;
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

