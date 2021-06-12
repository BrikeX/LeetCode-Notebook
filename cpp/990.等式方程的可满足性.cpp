/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class UF
{
private:
    int count;
    
    vector<int> parent, size;

public:
    UF(int n)
    {
        count = n;

        parent.resize(n);

        size.resize(n, 1);

        for (size_t i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    void unite(int p, int q)
    {
        int root_p = find(p);

        int root_q = find(q);

        if (root_p == root_q)
        {
            return;
        }
        
        if (size[root_p] > size[root_q])
        {
            parent[root_q] = root_p;

            size[root_p] += size[root_q];
        }
        else
        {
            parent[root_p] = root_q;

            size[root_q] += size[root_p];
        }
        
        count--;
    }

    bool isConnected(int p, int q)
    {
        int root_p = find(p);

        int root_q = find(q);

        return root_p == root_q;
    }

    int find(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];

            x = parent[x];
        }
        
        return x;
    }

    int countValue(void)
    {
        return count;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // 并查集算法
        UF uf(26);

        for (auto &&str : equations)
        {
            if (str[1] == '=')
            {
                uf.unite(str[0] - 'a', str[3] - 'a');
            }
        }
        
        for (auto &&str : equations)
        {
            if (str[1] == '!')
            {
                if (uf.isConnected(str[0] - 'a', str[3] - 'a'))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
// @lc code=end

