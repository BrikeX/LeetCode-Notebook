/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // 分治算法
        auto it = memo.find(expression);

        if (it != memo.end())
        {
            return it->second;
        }
        
        vector<int> result;

        for (size_t i = 0; i < expression.size(); i++)
        {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));

                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (auto &&a : left)
                {
                    for (auto &&b : right)
                    {
                        if (c == '+')
                        {
                            result.push_back(a + b);
                        }
                        else if (c == '-')
                        {
                            result.push_back(a - b);
                        }
                        else
                        {
                            result.push_back(a * b);
                        }
                    }
                }
            }
        }
        
        if (result.empty())
        {
            result.push_back(stoi(expression));
        }
        
        memo[expression] = result;

        return result;
    }

private:
    unordered_map<string, vector<int>> memo;
};
// @lc code=end

