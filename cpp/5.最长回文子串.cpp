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
        string result;

        for (int i = 0; i < s.size(); i++)
        {
            string s1 = palindrome(s, i, i);

            string s2 = palindrome(s, i, i + 1);

            result = result.size() > s1.size() ? result : s1;

            result = result.size() > s2.size() ? result : s2;
        }
        
        return result;
    }
    
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

