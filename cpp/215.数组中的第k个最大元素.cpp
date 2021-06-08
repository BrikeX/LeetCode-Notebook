/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // // 优先队列
        // priority_queue<int, vector<int>, greater<int>> q;

        // for (size_t i = 0; i < nums.size(); i++)
        // {            
        //     q.push(nums[i]);

        //     if (q.size() > k)
        //     {
        //         q.pop();
        //     }
        // }
        
        // return q.top();

        // 快速排序
        shuffle(nums);

        k = nums.size() - k;

        int left = 0, right = nums.size() - 1;

        int mid;

        while (left <= right)
        {
            mid = partition(nums, left, right);

            if (mid < k)
            {
                left = mid + 1;
            }
            else if (mid > k)
            {
                right = mid - 1;
            }
            else
            {
                return nums[mid];
            }
        }
        
        return -1;
    }

    void shuffle(vector<int>& nums)
    {
        int nums_size = nums.size();

        srand(time(NULL));

        for (int i = 0; i < nums_size; i++)
        {
            swapElement(nums, i, rand() % (nums_size - i) + i);
        }
    }

    void swapElement(vector<int>& nums, int i, int j)
    {
        if (i == j)
        {
            return;
        }
        
        int tmp = nums[i];

        nums[i] = nums[j];

        nums[j] = tmp;
    }

    int partition(vector<int>& nums, int left, int right)
    {
        if (left == right)
        {
            return left;
        }
        
        int pivot = nums[left];

        int i = left, j = right + 1;

        while (true)
        {
            while (nums[++i] < pivot)
            {
                if (i == right)
                {
                    break;
                }
            }
            
            while (nums[--j] > pivot)
            {
                if (j == left)
                {
                    break;
                }
            }
            
            if (i >= j)
            {
                break;
            }
            
            swapElement(nums, i, j);
        }
        
        swapElement(nums, j, left);

        return j;
    }
};
// @lc code=end

