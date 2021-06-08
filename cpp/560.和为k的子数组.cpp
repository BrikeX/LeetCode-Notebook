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
        unordered_map<int, int> memo;

        memo.emplace(0, 1);

        int result = 0;

        int sum_0_i = 0, sum_0_j = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            sum_0_i += nums[i];

            sum_0_j = sum_0_i - k;

            auto it = memo.find(sum_0_j);

            if (it != memo.end())
            {
                result += it->second;
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

