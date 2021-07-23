/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        // The Sieve of Eratosthenes
        if (n < 2)
        {
            return 0;
        }
        
        vector<bool> primes(n, true);

        int result = 0;

        for (int i = 2; i < n; i++)
        {
            if (primes[i])
            {
                result++;

                if ((long long) i * i < n)
                {
                    for (int j = i * i; j < n; j += i)
                    {
                        primes[j] = false;
                    }
                }
            }
        }
        
        return result;
    }
};
// @lc code=end

