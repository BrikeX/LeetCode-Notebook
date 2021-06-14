/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 单调栈
        vector<int> result(temperatures.size());

        stack<int> temp_stack;

        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!temp_stack.empty() && temperatures[temp_stack.top()] <= temperatures[i])
            {
                temp_stack.pop();
            }
            
            result[i] = temp_stack.empty() ? 0 : (temp_stack.top() - i);

            temp_stack.push(i);
        }
        
        return result;
    }
};
// @lc code=end

