/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 回溯算法
        int sum = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        
        if (sum % k)
        {
            return false;
        }

        // 防止超时
        sort(nums.begin(), nums.end(), comparison);
        
        vector<int> bucket(k);

        return backTracking(nums, 0, bucket, sum / k);
    }

    static bool comparison(const int& a, const int& b)
    {
        return a > b;
    }

    bool backTracking(vector<int>& nums, int index, vector<int>& bucket, int target)
    {
        if (index == nums.size())
        {
            for (size_t i = 0; i < bucket.size(); i++)
            {
                if (bucket[i] != target)
                {
                    return false;
                }
            }

            return true;
        }
        
        for (size_t i = 0; i < bucket.size(); i++)
        {
            if (bucket[i] + nums[index] > target)
            {
                continue;
            }
            
            bucket[i] += nums[index];

            if (backTracking(nums, index + 1, bucket, target))
            {
                return true;
            }
            
            bucket[i] -= nums[index];
        }
        
        return false;
    }
};
// @lc code=end

