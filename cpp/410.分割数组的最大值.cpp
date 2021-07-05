/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // 二分搜索
        int left = 0, right = 0;

        for (auto &&num : nums)
        {
            if (left < num)
            {
                left = num;
            }

            right += num;
        }
        
        int mid;

        int n;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            n = split(nums, mid);

            if (n <= m)
            {
                right = mid - 1;
            }
            else if (n > m)
            {
                left = mid + 1;
            }            
        }
        
        return left;
    }

    int split(vector<int>& nums, int m)
    {
        int count = 1;

        int sum = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] > m)
            {
                count++;

                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }
        }
        
        return count;
    }
};
// @lc code=end

