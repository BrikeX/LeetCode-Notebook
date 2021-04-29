/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 哈希表
        unordered_map<int, int> hash_table;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hash_table.find(target - nums[i]);

            if (it != hash_table.end())
            {
                return {it->second, i};
            }
            
            hash_table[nums[i]] = i;
        }

        return {};        

        // 暴力枚举
        // vector<int> result(2);

        // for (size_t i = 0; i < nums.size() - 1; i++)
        // {
        //     for (size_t j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             result[0] = i;

        //             result[1] = j;

        //             return result;
        //         }
        //     }
        // }

        // result.clear();
        
        // return result;
    }
};
// @lc code=end

