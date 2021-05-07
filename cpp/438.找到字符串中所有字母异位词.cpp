/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 滑窗算法
        unordered_map<char, int> need, window;

        for (size_t i = 0; i < p.size(); i++)
        {
            need[p[i]]++;
        }
        
        int left = 0, right = 0;

        int valid = 0;

        char c_left, c_right;

        vector<int> result;

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
            
            while (right - left >= p.size())
            {
                if (valid == need.size())
                {
                    result.push_back(left);
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
        
        return result;
    }
};
// @lc code=end

