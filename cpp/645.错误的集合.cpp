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

        int nums_size = nums.size();

        int normal_sum = (1 + nums_size) * nums_size / 2;

        int nomo_sum = 0;

        int index;

        for (auto &&num : nums)
        {
            index = abs(num) - 1;

            if (nums[index] < 0)
            {
                result[0] = abs(num);

                continue;
            }
            
            nomo_sum += abs(num);

            nums[index] *= -1;
        }
        
        result[1] = normal_sum - nomo_sum;

        return result;

        // vector<int> result(2);

        // int index;

        // for (auto &&num : nums)
        // {
        //     index = abs(num) - 1;

        //     if (nums[index] > 0)
        //     {
        //         nums[index] *= -1;
        //     }
        //     else
        //     {
        //         result[0] = abs(num);
        //     }
        // }
        
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     if (nums[i] > 0)
        //     {
        //         result[1] = ++i;

        //         break;
        //     }
        // }
        
        // return result;
    }
};
// @lc code=end

