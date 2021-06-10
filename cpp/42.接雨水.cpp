/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
        {
            return 0;
        }

        int result = 0;

        // 双指针算法
        int left = 0, right = height.size() - 1;

        int left_max = height.front();

        int right_max = height.back();

        while (left <= right)
        {
            left_max = max(left_max, height[left]);

            right_max = max(right_max, height[right]);

            if (left_max < right_max)
            {
                result += left_max - height[left];

                left++;
            }
            else
            {
                result += right_max - height[right];

                right--;
            }
        }
        
        return result;

        // // 备忘录
        // vector<int> left_max(height.size()), right_max(height.size());

        // left_max.front() = height.front();

        // right_max.back() = height.back();

        // for (int i = 1; i < height.size(); i++)
        // {
        //     left_max[i] = max(height[i], left_max[i - 1]);
        // }
        
        // for (int i = height.size() - 2; i >= 0; i--)
        // {
        //     right_max[i] = max(height[i], right_max[i + 1]);
        // }
        
        // for (size_t i = 1; i < height.size(); i++)
        // {
        //     result += min(left_max[i], right_max[i]) - height[i];
        // }
        
        // return result;

        // // 暴力穷举
        // int left_max, right_max;

        // for (size_t i = 1; i < height.size() - 1; i++)
        // {
        //     left_max = 0;

        //     right_max = 0;

        //     left_max = *max_element(height.begin(), height.begin() + i + 1);

        //     right_max = *max_element(height.begin() + i, height.end());

        //     result += min(left_max, right_max) - height[i];
        // }
        
        // return result;
    }
};
// @lc code=end

