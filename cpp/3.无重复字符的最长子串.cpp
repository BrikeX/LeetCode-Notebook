/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2)
        {
            return s.length();
        }

        // 滑动窗口
        unordered_map<char, int> window;

        int left = 0;

        int right = 0;

        int result = 0;

        char c_left, c_right;

        while (right < s.size())
        {
            c_right = s[right];

            right++;

            window[c_right]++;

            while (window[c_right] > 1)
            {
                c_left = s[left];

                left++;

                window[c_left]--;
            }
            
            result = max(result, right - left);
        }

        // 暴力循环
        // int result = 1;

        // int sum = result;

        // size_t i, j, k = 0;

        // while (k < s.length() - 1)
        // {
        //     for (i = k + 1; i < s.length(); i++)
        //     {
        //         // 检查从 s[k] 到 s[i-1] 是否有和 s[i] 一样的元素
        //         for (j = k; j < i; j++)
        //         {
        //             if (s[j] == s[i])
        //             {
        //                 break;
        //             }
        //         }

        //         if (j == i)
        //         {
        //             // 如果没有一样的，增加计数
        //             sum++;
        //         }
        //         else
        //         {
        //             // 如果有一样的，更新最大计数
        //             if (result < sum)
        //             {
        //                 result = sum;
        //             }

        //             // 重置 sum
        //             sum = 1;
                    
        //             // 更新 k，i
        //             k++;

        //             i = k;
        //         }
        //     }

        //     if (i == s.length())
        //     {
        //         if (result < sum)
        //         {
        //             result = sum;
        //         }
                
        //         k++;
        //     }

        //     if (result > s.length() - k)
        //     {
        //         break;
        //     }
        // }

        return result;
    }
};
// @lc code=end

