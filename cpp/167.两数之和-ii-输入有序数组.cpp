/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 双指针
        int left = 0, right = numbers.size() - 1;

        int sum;

        while (left < right)
        {
            sum = numbers[left] + numbers[right];

            if (sum == target)
            {
                return {left + 1, right + 1};
            }
            else if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
        }
        
        return {-1, -1};
    }
};
// @lc code=end

