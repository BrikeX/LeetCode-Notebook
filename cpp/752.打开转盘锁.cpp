/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // BFS
        string start = "0000";

        if (target == start)
        {
            return 0;
        }

        unordered_set<string> forbidden(deadends.begin(), deadends.end());

        if (forbidden.count(start))
        {
            return -1;
        }

        unordered_set<string> visited;

        queue<string> passwd_q;
        
        passwd_q.push(start);

        string passwd;

        int step = 0;

        int q_size;

        while (!passwd_q.empty())
        {
            q_size = passwd_q.size();

            for (size_t i = 0; i < q_size; i++)
            {
                passwd = passwd_q.front();

                if (passwd == target)
                {
                    return step;
                }

                passwd_q.pop();

                if (visited.count(passwd) || forbidden.count(passwd))
                {
                    continue;
                }

                visited.emplace(passwd);

                for (size_t j = 0; j < passwd.size(); j++)
                {
                    passwd_q.push(plusOne(passwd, j));

                    passwd_q.push(minusOne(passwd, j));
                }
            }

            step++;
        }
        
        return -1;
    }

    string plusOne(string passwd, size_t index)
    {
        if (passwd[index] == '9')
        {
            passwd[index] = '0';
        }
        else
        {
            passwd[index]++;
        }
        
        return passwd;
    }

    string minusOne(string passwd, size_t index)
    {
        if (passwd[index] == '0')
        {
            passwd[index] = '9';
        }
        else
        {
            passwd[index]--;
        }
        
        return passwd;
    }
};
// @lc code=end

