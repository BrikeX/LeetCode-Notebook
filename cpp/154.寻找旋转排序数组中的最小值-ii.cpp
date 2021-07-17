/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 二分搜索
        int nums_size = nums.size();

        if (nums_size == 1)
        {
            return nums[0];
        }
        
        if (nums_size == 2)
        {
            return min(nums[0], nums[1]);
        }
        
        int left = 0, right = nums_size - 1;
        
        int mid;

        while (left < right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right--;
            }
        }
        
        return nums[left];
    }
};
// @lc code=end

