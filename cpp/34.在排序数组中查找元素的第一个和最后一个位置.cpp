/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 二分搜索
        vector<int> result(2);

        if (nums.size() == 0)
        {
            result[0] = -1;

            result[1] = -1;
            
            return result;
        }
        
        int left = 0;

        int right = nums.size() - 1;

        int mid;

        // left boundary
        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] >= target)
            {
                right = mid - 1;
            }
        }
        
        if (left > nums.size() - 1 || nums[left] != target)
        {
            result[0] = -1;
        }
        else
        {
            result[0] = left;
        }
        
        // right boundary
        left = 0;

        right = nums.size() - 1;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }

        if (right < 0 || nums[right] != target)
        {
            result[1] = -1;
        }
        else
        {
            result[1] = right;
        }

        return result;
    }
};
// @lc code=end

