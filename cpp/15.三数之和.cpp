/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() < 3)
        {
            return result;
        }
        
        sort(nums.begin(), nums.end());

        int target = 0;

        vector<vector<int>> tuples;

        for (size_t i = 0; i < nums.size(); i++)
        {
            tuples = twoSum(nums, i + 1, target - nums[i]);

            for (size_t j = 0; j < tuples.size(); j++)
            {
                tuples[j].push_back(nums[i]);

                result.push_back(tuples[j]);
            }

            while (i < nums.size() - 1 && nums[i] == nums[i+1])
            {
                i++;
            }
        }
        
        return result;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int start, int target)
    {
        int i = start, j = nums.size() - 1;

        vector<vector<int>> result;

        int left, right, sum;

        while (i < j)
        {
            sum = nums[i] + nums[j];

            left = nums[i];

            right = nums[j];

            if (sum < target)
            {
                while (i < j && nums[i] == left)
                {
                    i++;
                }
            }
            else
            {
                if (sum > target)
                {
                    while (i < j && nums[j] == right)
                    {
                        j--;
                    }
                }
                else
                {
                    result.push_back({left, right});

                    while (i < j && nums[i] == left)
                    {
                        i++;
                    }
                    
                    while (i < j && nums[j] == right)
                    {
                        j--;
                    }
                }
            }
        }

        return result;
    }
};
// @lc code=end

