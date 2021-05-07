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
        queue<string> q_password;

        q_password.push("0000");

        unordered_set<string> visited;

        visited.emplace(q_password.front());

        int step = 0;

        int q_size;

        string str_tmp;

        string str_up, str_down;

        while (!q_password.empty())
        {
            q_size = q_password.size();

            for (size_t i = 0; i < q_size; i++)
            {
                str_tmp = q_password.front();

                q_password.pop();

                if (str_tmp == target)
                {
                    return step;
                }
                
                if (find(deadends.begin(), deadends.end(), str_tmp) != deadends.end())
                {
                    continue;
                }
                
                for (size_t j = 0; j < str_tmp.size(); j++)
                {
                    str_up = plusOne(str_tmp, j);

                    if (visited.find(str_up) == visited.end())
                    {
                        q_password.push(str_up);

                        visited.emplace(str_up);
                    }
                    
                    str_down = minusOne(str_tmp, j);

                    if (visited.find(str_down) == visited.end())
                    {
                        q_password.push(str_down);

                        visited.emplace(str_down);
                    }
                }
            }
            
            step++;
        }
        
        return -1;
    }

    string plusOne(string str, const size_t& j)
    {
        if (str[j] == '9')
        {
            str[j] = '0';
        }
        else
        {
            str[j] += 1;
        }
        
        return str;
    }

    string minusOne(string str, const size_t& j)
    {
        if (str[j] == '0')
        {
            str[j] = '9';
        }
        else
        {
            str[j] -= 1;
        }
        
        return str;
    }
};
// @lc code=end

