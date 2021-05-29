/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 双指针算法
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int slow = 0, fast = 0;

        while (fast < nums.size())
        {
            if (nums[slow] != nums[fast])
            {
                slow++;

                nums[slow] = nums[fast];
            }
            
            fast++;
        }
        
        return slow + 1;
    }
};
// @lc code=end

