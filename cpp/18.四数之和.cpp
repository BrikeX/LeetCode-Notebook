/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // nSum
        vector<vector<int>> result;

        int n = 4;

        if (nums.size() < n)
        {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        return nSum(nums, n, 0, target);
    }

    vector<vector<int>> nSum(vector<int>& nums, int n, int start, int target)
    {
        vector<vector<int>> result;

        if (n < 2 || nums.size() < n)
        {
            return result;
        }
        
        if (n == 2)
        {
            int i = start, j = nums.size() - 1;

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
        }
        else
        {
            for (size_t i = start; i < nums.size(); i++)
            {
                vector<vector<int>> sub = nSum(nums, n - 1, i + 1, target - nums[i]);

                for (size_t j = 0; j < sub.size(); j++)
                {
                    sub[j].push_back(nums[i]);

                    result.push_back(sub[j]);
                }
                
                while (i < nums.size() - 1 && nums[i] == nums[i+1])
                {
                    i++;
                }
            }
        }
        
        return result;
    }
};
// @lc code=end

