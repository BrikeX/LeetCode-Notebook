/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分搜索
        int nums_size = nums.size();

        if (nums_size == 1)
        {
            return target == nums[0] ? 0 : -1;
        }
        
        int left = 0, right = nums_size - 1;

        int mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[0] <= nums[mid])
            {
                if (nums[0] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums.back())
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
// @lc code=end

