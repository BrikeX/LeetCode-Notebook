/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class KMP
{
private:
    vector<vector<int>> dp_table;

    string pat;

public:
    KMP(string& str)
    {
        pat = str;

        dp_table.resize(pat.size(), vector<int>(256));

        dp_table[0][pat[0]] = 1;

        int x = 0;

        for (size_t i = 1; i < pat.size(); i++)
        {
            for (size_t c = 0; c < 256; c++)
            {
                if (pat[i] == c)
                {
                    dp_table[i][c] = i + 1;
                }
                else
                {
                    dp_table[i][c] = dp_table[x][c];
                }
            }
            
            x = dp_table[x][pat[i]];
        }
    }

    int search(string& txt)
    {
        int j = 0;

        for (int i = 0; i < txt.size(); i++)
        {
            j = dp_table[j][txt[i]];

            if (j == pat.size())
            {
                return i - pat.size() + 1;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        // KMP (DP)
        if (needle.empty())
        {
            return 0;
        }
        
        if (haystack.empty())
        {
            return -1;
        }

        KMP kmp(needle);

        return kmp.search(haystack);
    }
};

// @lc code=end
