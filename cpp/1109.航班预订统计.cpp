/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
// class Difference
// {
// private:
//     vector<int> diff;
    
// public:
//     Difference(vector<int>& nums)
//     {
//         assert (nums.size() > 0);

//         diff.resize(nums.size());

//         diff[0] = nums[0];

//         for (size_t i = 1; i < diff.size(); i++)
//         {
//             diff[i] = nums[i] - nums[i - 1];
//         }
//     }

//     void increment(int i, int j, int value)
//     {
//         diff[i] += value;

//         if (j + 1 < diff.size())
//         {
//             diff[j + 1] -= value;
//         }
//     }

//     vector<int> result(void)
//     {
//         vector<int> result(diff.size());

//         result[0] = diff[0];

//         for (size_t i = 1; i < result.size(); i++)
//         {
//             result[i] = result[i - 1] + diff[i];
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 差分数组
        vector<int> result(n);

        for (auto &&booking : bookings)
        {
            result[booking[0] - 1] += booking[2];

            if (booking[1] < n)
            {
                result[booking[1]] -= booking[2];
            }
        }
        
        for (int i = 1; i < n; i++)
        {
            result[i] += result[i - 1];
        }
        
        return result;

        // vector<int> nums(n);

        // Difference df(nums);

        // for (auto &&booking : bookings)
        // {
        //     df.increment(booking[0] - 1, booking[1] - 1, booking[2]);
        // }
        
        // return df.result();
    }
};
// @lc code=end

