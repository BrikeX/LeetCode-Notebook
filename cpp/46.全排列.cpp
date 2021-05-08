/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 回溯算法
        vector<int> track;

        vector<vector<int>> result;

        backTracking(nums, track, result);

        return result;
    }

    void backTracking(vector<int>& nums, vector<int>& track, vector<vector<int>>& result)
    {
        if (track.size() == nums.size())
        {
            result.push_back(track);

            return;
        }
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (find(track.begin(), track.end(), nums[i]) != track.end())
            {
                continue;
            }
            else
            {
                track.push_back(nums[i]);

                backTracking(nums, track, result);

                track.pop_back();
            }
        }
    }
};
// @lc code=end

