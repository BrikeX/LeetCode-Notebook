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
        if (nums.size() == 1)
        {
            result.push_back(nums);

            return result;
        }
        
        backtracking(nums, track);

        return result;
    }

private:
    vector<int> track;

    vector<vector<int>> result;

    void backtracking(vector<int>& nums, vector<int>& track)
    {
        if (track.size() == nums.size())
        {
            result.push_back(track);

            return;
        }

        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (find(track.begin(), track.end(), *it) != track.end())
            {
                continue;
            }

            track.push_back(*it);

            backtracking(nums, track);

            track.pop_back();
        }
    }
};
// @lc code=end

