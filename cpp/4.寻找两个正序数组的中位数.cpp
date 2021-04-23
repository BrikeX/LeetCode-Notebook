/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {        
        priority_queue<int, vector<int>, greater<int> > nums_queue;

        for (size_t i = 0; i < nums1.size(); i++)
        {
            nums_queue.push(nums1[i]);
        }
        
        for (size_t i = 0; i < nums2.size(); i++)
        {
            nums_queue.push(nums2[i]);
        }
        
        vector<int> nums_vector;

        while (!nums_queue.empty())
        {
            nums_vector.push_back(nums_queue.top());
            
            nums_queue.pop();
        }

        double result;

        if (nums_vector.size() % 2 == 0)
        {
            result = (nums_vector[nums_vector.size() / 2] + nums_vector[nums_vector.size() / 2 - 1]) / 2.0;
        }
        else
        {
            result = nums_vector[nums_vector.size() / 2];
        }
        
        return result;
    }
};
// @lc code=end

