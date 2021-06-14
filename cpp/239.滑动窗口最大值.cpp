/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class MonotonicQueue
{
private:
    deque<int> nums;
    
public:
    void push(int num)
    {
        while (!nums.empty() && nums.back() < num)
        {
            nums.pop_back();
        }
        
        nums.push_back(num);
    }

    int max(void)
    {
        return nums.front();
    }

    void pop(int num)
    {
        if (!nums.empty() && nums.front() == num)
        {
            nums.pop_front();
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        MonotonicQueue window;

        for (int i = 0; i < k - 1; i++)
        {
            window.push(nums[i]);
        }
        
        for (int i = k - 1; i < nums.size(); i++)
        {
            window.push(nums[i]);

            result.push_back(window.max());

            window.pop(nums[i - k + 1]);
        }
        
        return result;
    }
};
// @lc code=end

