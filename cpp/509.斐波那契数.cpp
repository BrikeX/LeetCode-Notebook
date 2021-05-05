/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int memo(unordered_map<int, int>& hash_table, int n)
    {
        auto it = hash_table.find(n);

        if (it != hash_table.end())
        {
            return it->second;
        }
        else
        {
            hash_table[n] = memo(hash_table, n-1) + memo(hash_table, n-2);

            return hash_table[n];
        }
    }

    int fib(int n) {
        // 哈希表
        if (n < 1)
        {
            return 0;
        }
        
        if (n == 1 || n == 2)
        {
            return 1;
        }
        
        unordered_map<int, int> hash_table = {{0, 0}, {1, 1}, {2, 1}};

        return memo(hash_table, n);
        
        // // 暴力递归
        // if (n < 1)
        // {
        //     return 0;
        // }
        
        // if (n == 1 || n == 2)
        // {
        //     return 1;
        // }
        
        // return (fib(n-1) + fib(n-2));
    }
};
// @lc code=end

