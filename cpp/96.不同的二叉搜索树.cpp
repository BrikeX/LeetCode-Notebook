/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> memo;

    int numTrees(int n) {
        // DP
        if (n == 1)
        {
            return 1;
        }
        
        memo.resize(n + 1);

        for (size_t i = 0; i < memo.size(); i++)
        {
            memo[i].resize(n + 1);
        }
        
        return countTrees(1, n);
    }

    int countTrees(int start, int end)
    {
        if (start > end)
        {
            return 1;
        }

        if (memo[start][end])
        {
            return memo[start][end];
        }
        
        int result = 0;

        for (int i = start; i <= end; i++)
        {
            int left = countTrees(start, i - 1);

            int right = countTrees(i + 1, end);

            result += left * right;
        }

        memo[start][end] = result;
        
        return result;
    }
};
// @lc code=end

