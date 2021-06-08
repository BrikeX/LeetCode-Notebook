/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 优先队列
        priority_queue<int, vector<int>, greater<int>> q;

        for (size_t i = 0; i < nums.size(); i++)
        {            
            q.push(nums[i]);

            if (q.size() > k)
            {
                q.pop();
            }
        }
        
        return q.top();
    }
};
// @lc code=end

