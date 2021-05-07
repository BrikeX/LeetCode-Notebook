/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 滑窗算法
        unordered_map<char, int> need, window;

        for (size_t i = 0; i < s1.size(); i++)
        {
            need[s1[i]]++;
        }
        
        int left = 0, right = 0;

        int valid = 0;

        char c_left, c_right;

        while (right < s2.size())
        {
            c_right = s2[right];

            right++;

            if (need.count(c_right))
            {
                window[c_right]++;

                if (need[c_right] == window[c_right])
                {
                    valid++;
                }
            }
            
            while (right - left >= s1.size())
            {
                if (valid == need.size())
                {
                    return true;
                }
                
                c_left = s2[left];

                left++;

                if (need.count(c_left))
                {
                    if (need[c_left] == window[c_left])
                    {
                        valid--;
                    }
                    
                    window[c_left]--;
                }
            }
        }
        
        return false;
    }
};
// @lc code=end

