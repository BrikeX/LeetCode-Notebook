/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int nums_size = nums.size();

        for (auto &&num : nums)
        {
            int i = (num - 1) % nums_size;

            nums[i] += nums_size;
        }
        
        vector<int> result;

        for (size_t i = 0; i < nums_size; i++)
        {
            if (nums[i] <= nums_size)
            {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};
// @lc code=end

