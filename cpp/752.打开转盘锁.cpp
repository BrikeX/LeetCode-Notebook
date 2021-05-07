/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Bidirectional BFS
        unordered_set<string> set_1, set_2;

        unordered_set<string> visited;

        unordered_set<string> set_tmp;

        set_1.emplace("0000");

        set_2.emplace(target);
        
        int step = 0;

        string str_up, str_down;

        while (!set_1.empty() && !set_2.empty())
        {   
            set_tmp.clear();
            
            for (const string& str : set_1)
            {
                if (set_2.find(str) != set_2.end())
                {
                    return step;
                }
                
                if (find(deadends.begin(), deadends.end(), str) != deadends.end())
                {
                    continue;
                }
                
                visited.emplace(str);

                for (size_t i = 0; i < str.size(); i++)
                {
                    str_up = plusOne(str, i);

                    if (visited.find(str_up) == visited.end())
                    {
                        set_tmp.emplace(str_up);
                    }
                    
                    str_down = minusOne(str, i);

                    if (visited.find(str_down) == visited.end())
                    {
                        set_tmp.emplace(str_down);
                    }
                }
            }
            
            step++;

            set_1 = set_2;

            set_2 = set_tmp;
        }
        
        return -1;

        // // BFS
        // queue<string> q_password;

        // q_password.push("0000");

        // unordered_set<string> visited;

        // visited.emplace(q_password.front());

        // int step = 0;

        // int q_size;

        // string str_tmp;

        // string str_up, str_down;

        // while (!q_password.empty())
        // {
        //     q_size = q_password.size();

        //     for (size_t i = 0; i < q_size; i++)
        //     {
        //         str_tmp = q_password.front();

        //         q_password.pop();

        //         if (str_tmp == target)
        //         {
        //             return step;
        //         }
                
        //         if (find(deadends.begin(), deadends.end(), str_tmp) != deadends.end())
        //         {
        //             continue;
        //         }
                
        //         for (size_t j = 0; j < str_tmp.size(); j++)
        //         {
        //             str_up = plusOne(str_tmp, j);

        //             if (visited.find(str_up) == visited.end())
        //             {
        //                 q_password.push(str_up);

        //                 visited.emplace(str_up);
        //             }
                    
        //             str_down = minusOne(str_tmp, j);

        //             if (visited.find(str_down) == visited.end())
        //             {
        //                 q_password.push(str_down);

        //                 visited.emplace(str_down);
        //             }
        //         }
        //     }
            
        //     step++;
        // }
        
        // return -1;
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

