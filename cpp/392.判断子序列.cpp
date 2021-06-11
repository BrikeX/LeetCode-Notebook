/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 二分搜索
        unordered_map<char, vector<int>> memo;

        for (size_t i = 0; i < t.size(); i++)
        {
            memo[t[i]].push_back(i);
        }
        
        int j = 0;

        for (size_t i = 0; i < s.size(); i++)
        {
            if (!memo.count(s[i]))
            {
                return false;
            }
            
            int index = leftBoundary(memo[s[i]], j);

            if (index == memo[s[i]].size())
            {
                return false;
            }
            
            j = memo[s[i]][index] + 1;
        }
        
        return true;

        // // 双指针算法
        // int i = 0, j = 0;

        // while (i < s.size() && j < t.size())
        // {
        //     if (s[i] == t[j])
        //     {
        //         i++;
        //     }
            
        //     j++;
        // }
        
        // return i == s.size();
    }

    int leftBoundary(vector<int> vec, int target)
    {
        int left = 0, right = vec.size() - 1;

        int mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (vec[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        return left;
    }
};
// @lc code=end

