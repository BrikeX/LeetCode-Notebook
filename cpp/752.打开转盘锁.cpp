/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // // Bidirectional BFS
        // string start = "0000";

        // if (target == start)
        // {
        //     return 0;
        // }

        // unordered_set<string> forbidden(deadends.begin(), deadends.end());

        // if (forbidden.count(start))
        // {
        //     return -1;
        // }

        // unordered_set<string> visited;

        // unordered_set<string> set_1, set_2, set_tmp;

        // set_1.emplace(start);

        // set_2.emplace(target);

        // int step = 0;

        // string passwd_plus, passwd_minus;

        // while (!set_1.empty() && !set_2.empty())
        // {
        //     if (set_1.size() > set_2.size())
        //     {
        //         set_1.swap(set_2);
        //     }
            
        //     set_tmp.clear();

        //     for (auto &&passwd : set_1)
        //     {
        //         if (set_2.count(passwd))
        //         {
        //             return step;
        //         }

        //         visited.emplace(passwd);
                
        //         for (size_t i = 0; i < passwd.size(); i++)
        //         {
        //             passwd_plus = plusOne(passwd, i);

        //             if (!visited.count(passwd_plus) && !forbidden.count(passwd_plus))
        //             {
        //                 set_tmp.emplace(passwd_plus);
        //             }
                    
        //             passwd_minus = minusOne(passwd, i);

        //             if (!visited.count(passwd_minus) && !forbidden.count(passwd_minus))
        //             {
        //                 set_tmp.emplace(passwd_minus);
        //             }
        //         }
        //     }
            
        //     step++;

        //     set_1 = set_2;

        //     set_2 = set_tmp;
        // }
        
        // return -1;
        
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

        visited.emplace(start);

        string passwd;

        int step = 0;

        int q_size;

        string str_up, str_down;

        while (!passwd_q.empty())
        {
            q_size = passwd_q.size();

            for (size_t i = 0; i < q_size; i++)
            {
                passwd = passwd_q.front();

                passwd_q.pop();

                for (size_t j = 0; j < passwd.size(); j++)
                {
                    str_up = plusOne(passwd, j);

                    if (str_up == target)
                    {
                        return step + 1;
                    }

                    if (!visited.count(str_up) && !forbidden.count(str_up))
                    {
                        passwd_q.push(str_up);

                        visited.emplace(str_up);
                    }

                    str_down = minusOne(passwd, j);

                    if (str_down == target)
                    {
                        return step + 1;
                    }

                    if (!visited.count(str_down) && !forbidden.count(str_down))
                    {
                        passwd_q.push(str_down);

                        visited.emplace(str_down);
                    }
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

