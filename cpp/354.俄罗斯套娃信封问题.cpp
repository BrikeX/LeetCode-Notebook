/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    static bool envelopes_comparison(const vector<int>& a, const vector<int>& b)
    {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), envelopes_comparison);

        vector<int> height(envelopes.size());

        for (size_t i = 0; i < height.size(); i++)
        {
            height[i] = envelopes[i][1];
        }
        
        return lengthOfLIS(height);
    }

    int lengthOfLIS(vector<int>& height)
    {
        // DP
        vector<int> dp_table(height.size(), 1);

        int result = dp_table[0];

        for (size_t i = 0; i < height.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (height[i] > height[j])
                {
                    dp_table[i] = max(dp_table[i], dp_table[j] + 1);
                }
            }

            result = max(result, dp_table[i]);
        }
        
        return result;

        // return *max_element(dp_table.begin(), dp_table.end());

        // // 二分搜索
        // vector<int> top(height.size());

        // int piles = 0;

        // int left, right, mid;

        // for (size_t i = 0; i < height.size(); i++)
        // {
        //     left = 0;

        //     right = piles;

        //     while (left < right)
        //     {
        //         mid = left + (right - left) / 2;

        //         if (top[mid] >= height[i])
        //         {
        //             right = mid;
        //         }
        //         else
        //         {
        //             left = mid + 1;
        //         }
        //     }

        //     if (left == piles)
        //     {
        //         piles++;
        //     }

        //     top[left] = height[i];
        // }

        // return piles;
    }
};
// @lc code=end

