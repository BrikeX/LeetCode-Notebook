/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, int> memo;

    int dp(vector<int>& nums, int start, int rest)
    {
        if (start == nums.size())
        {
            if (rest == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        stringstream ss;

        ss << start;

        string str = ss.str();

        str += ",";

        ss.clear();

        ss.str("");

        ss << rest;

        str += ss.str();

        auto it = memo.find(str);

        if (it != memo.end())
        {
            return it->second;
        }
        
        int result = dp(nums, start + 1, rest - nums[start]) + 
                     dp(nums, start + 1, rest + nums[start]);

        memo.emplace(str, result);

        return result;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // DP
        return dp(nums, 0, target);
    }
};
// @lc code=end

