/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start
class Solution {
public:
    int base = 1337;

    int superPow(int a, vector<int>& b) {
        if (b.empty())
        {
            return 1;
        }
        
        int last = b.back();

        b.pop_back();

        int part1 = superMod(a, last);

        int part2 = superMod(superPow(a, b), 10);

        return (part1 * part2) % base;
    }

    int superMod(int a, int k)
    {
        if (k == 0)
        {
            return 1;
        }
        
        a %= base;

        if (k % 2)
        {
            return (a * superMod(a, k - 1)) % base;
        }
        else
        {
            int sub = superMod(a, k / 2);

            return (sub * sub) % base;
        }
    }
};
// @lc code=end

