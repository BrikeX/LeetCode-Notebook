/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 双指针算法
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            if (nums[left] == val)
            {
                swap(nums[left], nums[right--]);
            }
            else
            {
                ++left;
            }
        }
        
        return left;

        // int slow = 0, fast = 0;

        // while (fast < nums.size())
        // {
        //     if (nums[fast] != val)
        //     {
        //         nums[slow++] = nums[fast];
        //     }
            
        //     ++fast;
        // }
        
        // return slow;
    }
};
// @lc code=end

