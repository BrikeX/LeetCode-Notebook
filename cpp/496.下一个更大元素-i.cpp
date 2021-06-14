/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 单调栈
        vector<int> result(nums1.size());

        unordered_map<int, int> num_map;

        stack<int> num_stack;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!num_stack.empty() && num_stack.top() <= nums2[i])
            {
                num_stack.pop();
            }

            int num = num_stack.empty() ? -1 : num_stack.top();

            num_map.emplace(nums2[i], num);

            num_stack.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            result[i] = num_map[nums1[i]];
        }
        
        return result;
    }
};
// @lc code=end

