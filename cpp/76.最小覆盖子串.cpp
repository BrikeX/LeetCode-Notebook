/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // 滑窗算法
        unordered_map<char, int> need, window;

        for (size_t i = 0; i < t.size(); i++)
        {
            need[t[i]]++;
        }
        
        int left = 0, right = 0;

        int valid = 0;

        int start = 0, len = INT_MAX;

        char c_left, c_right;

        while (right < s.size())
        {
            c_right = s[right];

            right++;

            if (need.count(c_right))
            {
                window[c_right]++;

                if (need[c_right] == window[c_right])
                {
                    valid++;
                }
            }
            
            while (valid == need.size())
            {
                if (right - left < len)
                {
                    start = left;

                    len = right - left;
                }
                
                c_left = s[left];

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
        
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};
// @lc code=end

