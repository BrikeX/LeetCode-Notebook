/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 双指针算法
        int i = 0, j = 0;

        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
            }
            
            j++;
        }
        
        return i == s.size();
    }
};
// @lc code=end

