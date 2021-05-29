/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        // 哈希表
        whitelist_size = n - blacklist.size();

        for (size_t i = 0; i < blacklist.size(); i++)
        {
            memo[blacklist[i]] = 1;
        }
        
        int index = n - 1;

        for (size_t i = 0; i < blacklist.size(); i++)
        {
            if (blacklist[i] >= whitelist_size)
            {
                continue;
            }
            
            while (memo.count(index))
            {
                index--;
            }
            
            memo[blacklist[i]] = index;

            index--;
        }
    }
    
    int pick() {
        int index = rand() % whitelist_size;

        auto it = memo.find(index);

        if (it != memo.end())
        {
            return it->second;
        }
        
        return index;
    }

private:
    int whitelist_size;

    unordered_map<int, int> memo;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

