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

        for (auto &&num : nums)
        {
            sum += num;
        }
        
        if (sum % k)
        {
            return false;
        }

        // // 从数字视角
        // sort(nums.begin(), nums.end(), comparison);

        // vector<int> buckets(k);

        // return backTracking(nums, buckets, 0, sum / k);

        // 从容器视角
        vector<bool> used(nums.size());

        return backTracking(k, 0, nums, 0, used, sum / k);
    }

private:
    bool backTracking(int k, int bucket, vector<int>& nums, int start, vector<bool>& used, int target)
    {
        if (k == 0)
        {
            return true;
        }
        
        if (bucket == target)
        {
            return backTracking(k - 1, 0, nums, 0, used, target);
        }
        
        for (int i = start; i < nums.size(); i++)
        {
            if (used[i])
            {
                continue;
            }
            
            if (bucket + nums[i] > target)
            {
                continue;
            }
            
            bucket += nums[i];

            used[i] = true;

            if (backTracking(k, bucket, nums, i + 1, used, target))
            {
                return true;
            }
            
            bucket -= nums[i];

            used[i] = false;
        }
        
        return false;
    }

    // static bool comparison(const int& a, const int& b)
    // {
    //     return a > b;
    // }

    // bool backTracking(vector<int>& nums, vector<int>& buckets, int index, int target)
    // {
    //     if (index == nums.size())
    //     {
    //         for (auto &&bucket : buckets)
    //         {
    //             if (bucket != target)
    //             {
    //                 return false;
    //             }
    //         }
            
    //         return true;
    //     }
        
    //     for (auto &&bucket : buckets)
    //     {
    //         if (bucket + nums[index] > target)
    //         {
    //             continue;
    //         }
            
    //         bucket += nums[index];

    //         if (backTracking(nums, buckets, index + 1, target))
    //         {
    //             return true;
    //         }
            
    //         bucket -= nums[index];
    //     }
        
    //     return false;
    // }
};
// @lc code=end

