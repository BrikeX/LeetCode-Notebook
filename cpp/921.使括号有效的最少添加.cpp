/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int left_bracket = 0, right_bracket = 0;

        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                right_bracket++;
            }
            
            if (s[i] == ')')
            {
                right_bracket--;

                if (right_bracket == -1)
                {
                    left_bracket++;

                    right_bracket = 0;
                }
            }
        }
        
        return left_bracket + right_bracket;
    }
};
// @lc code=end

