/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 双指针算法
        int slow = 0, fast = 0;

        while (fast < nums.size())
        {
            if (nums[fast])
            {
                swap(nums[slow++], nums[fast]);
            }
            
            ++fast;
        }

        // int i = removeElement(nums, 0);

        // for (; i < nums.size(); ++i)
        // {
        //     nums[i] = 0;
        // }
    }

// private:
//     int removeElement(vector<int>& nums, int val)
//     {
//         int slow = 0, fast = 0;

//         while (fast < nums.size())
//         {
//             if (nums[fast] != val)
//             {
//                 nums[slow++] = nums[fast];
//             }
            
//             ++fast;
//         }
        
//         return slow;
//     }
};
// @lc code=end

