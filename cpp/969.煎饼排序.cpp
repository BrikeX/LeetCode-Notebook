/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        // 递归算法
        pancakeSwap(arr, arr.size());

        return result;
    }

    void pancakeSwap(vector<int>& arr, int size)
    {
        if (size == 1)
        {
            return;
        }
        
        int index = max_element(arr.begin(), arr.begin() + size) - arr.begin();
        
        reverse(arr.begin(), arr.begin() + index + 1);

        result.push_back(index + 1);

        reverse(arr.begin(), arr.begin() + size);

        result.push_back(size);

        pancakeSwap(arr, size - 1);
    }

private:
    vector<int> result;
};
// @lc code=end

