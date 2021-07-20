/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 前缀和，哈希表
        if (nums.size() == 1)
        {
            if (nums[0] == k)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        unordered_map<int, int> memo({{0, 1}});

        int result = 0;

        int sum_0_i = 0, sum_0_j = 0;

        for (auto &&num : nums)
        {
            sum_0_i += num;

            sum_0_j = sum_0_i - k;

            if (memo.count(sum_0_j))
            {
                result += memo[sum_0_j];
            }
            
            memo[sum_0_i]++;
        }
        
        return result;

        // 穷举法，超时
        // vector<int> sums(nums.size() + 1, 0);

        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     sums[i + 1] = sums[i] + nums[i];
        // }
        
        // int result = 0;

        // for (size_t i = 1; i < sums.size(); i++)
        // {
        //     for (size_t j = 0; j < i; j++)
        //     {
        //         if (sums[i] - sums[j] == k)
        //         {
        //             result++;
        //         }
        //     }
        // }
        
        // return result;
    }
};
// @lc code=end

