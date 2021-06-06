/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;

    void backTracking(vector<int>& nums, int start, vector<int>& track)
    {
        result.push_back(track);

        for (size_t i = start; i < nums.size(); i++)
        {
            track.push_back(nums[i]);

            backTracking(nums, i + 1, track);

            track.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // 回溯算法
        vector<int> track;

        backTracking(nums, 0, track);

        return result;

        // // 数学归纳法
        // if (nums.empty())
        // {
        //     return {{}};
        // }
        
        // int back_element = nums.back();

        // nums.pop_back();

        // vector<vector<int>> result = subsets(nums);

        // int result_size = result.size();

        // for (size_t i = 0; i < result_size; i++)
        // {
        //     result.push_back(result[i]);

        //     result.back().push_back(back_element);
        // }
        
        // return result;
    }
};
// @lc code=end

