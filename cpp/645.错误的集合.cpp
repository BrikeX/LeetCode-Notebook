/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);

        int index;

        for (auto &&num : nums)
        {
            index = abs(num) - 1;

            if (nums[index] > 0)
            {
                nums[index] *= -1;
            }
            else
            {
                result[0] = abs(num);
            }
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                result[1] = ++i;

                break;
            }
        }
        
        return result;
    }
};
// @lc code=end

