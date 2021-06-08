/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
class Solution {
public:
    Solution(vector<int>& nums) {
        ptr = &nums;

        srand(time(NULL));
    }
    
    int pick(int target) {
        // 水塘抽样算法
        int count = 0;

        int result;

        for (size_t i = 0; i < (*ptr).size(); i++)
        {
            if ((*ptr)[i] == target)
            {
                if (rand() % ++count == 0)
                {
                    result = i;
                }
            }
        }
        
        return result;
    }

private:
    vector<int>* ptr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

