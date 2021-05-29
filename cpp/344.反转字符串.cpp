/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        // 双指针算法
        int left = 0, right = s.size() - 1;

        char c;

        while (left < right)
        {
            c = s[left];

            s[left] = s[right];

            s[right] = c;

            left++;

            right--;
        }
        
        return;
    }
};
// @lc code=end

