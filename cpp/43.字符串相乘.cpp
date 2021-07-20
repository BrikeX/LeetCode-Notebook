/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        
        vector<int> data(num1.size() + num2.size());

        int sum = 0;

        for (int i = num1.size() - 1; i >= 0; i--)
        {
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                sum = (num1[i] - '0') * (num2[j] - '0') + data[i + j + 1];

                data[i + j + 1] = sum % 10;

                data[i + j] += sum / 10;
            }
        }

        auto it = data.begin();

        while (it != data.end() && *it == 0)
        {
            it++;
        }
        
        string result;

        for (; it != data.end(); it++)
        {
            result += to_string(*it);
        }
        
        return result;
    }
};
// @lc code=end

