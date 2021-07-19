/*
 * @lc app=leetcode.cn id=1541 lang=cpp
 *
 * [1541] 平衡括号字符串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int insert_bracket = 0, need_bracket = 0;
        
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                need_bracket += 2;

                if (need_bracket % 2)
                {
                    insert_bracket++;

                    need_bracket--;
                }
            }
            
            if (s[i] == ')')
            {
                need_bracket--;

                if (need_bracket == -1)
                {
                    insert_bracket++;

                    need_bracket = 1;
                }
            }
        }
        
        return insert_bracket + need_bracket;
    }
};
// @lc code=end

