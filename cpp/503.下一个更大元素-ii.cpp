/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 单调栈
        int nums_size = nums.size();

        vector<int> result(nums_size);

        stack<int> num_stack;

        for (int i = 2 * nums_size - 1; i >= 0; i--)
        {
            while (!num_stack.empty() && num_stack.top() <= nums[i % nums_size])
            {
                num_stack.pop();
            }
            
            result[i % nums_size] = num_stack.empty() ? -1 : num_stack.top();

            num_stack.push(nums[i % nums_size]);
        }
        
        return result;
    }
};
// @lc code=end

