/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, int> memo;

    int superEggDrop(int k, int n) {
        // DP
        vector<vector<int>> dp_table(k + 1, vector<int>(n + 1));

        int drop_max = 0;

        while (dp_table[k][drop_max] < n)
        {
            drop_max++;

            for (int i = 1; i <= k; i++)
            {
                dp_table[i][drop_max] = dp_table[i][drop_max - 1] + 
                                        dp_table[i - 1][drop_max - 1] + 
                                        1;
            }
        }

        return drop_max;

        // return dp(k, n);
    }

    int dp(int k, int n)
    {
        if (k == 1)
        {
            return n;
        }
        
        if (n == 0)
        {
            return 0;
        }

        stringstream ss;

        ss << k;

        string key = ss.str();
        
        key += ",";

        ss.clear();

        ss.str("");

        ss << n;

        key += ss.str();

        if (memo.count(key))
        {
            return memo[key];
        }

        int result = INT_MAX;
        
        // 超时
        // for (int i = 1; i <= n; i++)
        // {
        //     result = min(result, 
        //                  max(dp(k, n - i), dp(k - 1, i - 1)) + 1);
        // }

        // 二分法，超时
        int low = 1, high = n;

        int mid;

        int broken, not_broken;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            broken = dp(k - 1, mid - 1);

            not_broken = dp(k, n - mid);

            if (broken > not_broken)
            {
                high = mid - 1;

                result = min(result, broken + 1);
            }
            else
            {
                low = mid + 1;

                result = min(result, not_broken + 1);
            }
        }

        memo[key] = result;
        
        return result;
    }
};
// @lc code=end

