/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int nums_size = nums.size();

        if (nums_size == 1)
        {
            return target == nums[0];
        }

        // 二分搜索
        int left = 0, right = nums_size - 1;

        int mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return true;
            }
            
            if (nums[left] == nums[mid] && nums[right] == nums[mid])
            {
                left++;

                right--;
            }
            else if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
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
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        
        return false;
        
        // // 遍历
        // for (auto &&num : nums)
        // {
        //     if (num == target)
        //     {
        //         return true;
        //     }
        // }
        
        // return false;
    }
};
// @lc code=end

