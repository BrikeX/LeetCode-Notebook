/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        // 双指针算法
        if (s.size() == 1)
        {
            return s;
        }
        
        if (s.size() == 2)
        {
            return s[0] == s[1] ? s : s.substr(0, 1);
        }

        string result, s1, s2;

        for (int i = 0; i < s.size(); i++)
        {
            s1 = palindrome(s, i, i);
            
            s2 = palindrome(s, i, i + 1);

            if (result.size() < s1.size())
            {
                result = s1;
            }
            
            if (result.size() < s2.size())
            {
                result = s2;
            }
        }
        
        return result;
    }

private:
    string palindrome(string& s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;

            right++;
        }
        
        return s.substr(left + 1, right - left - 1);
    }
};
// @lc code=end

