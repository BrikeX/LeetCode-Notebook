/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
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
    int row, col;

    void dfs(vector<vector<char>>& board, int x, int y)
    {
        if (x < 0 || x >= row || y < 0 || y >= col || board[x][y] != 'O')
        {
            return;
        }
        
        board[x][y] = '#';

        dfs(board, x + 1, y);

        dfs(board, x - 1, y);

        dfs(board, x, y + 1);

        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        // DFS
        row = board.size();

        col = board[0].size();

        for (int i = 0; i < row; i++)
        {
            dfs(board, i, 0);

            dfs(board, i, col - 1);
        }
        
        for (int j = 0; j < col; j++)
        {
            dfs(board, 0, j);

            dfs(board, row - 1, j);
        }
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }

        // // 并查集算法
        // int row = board.size();

        // int col = board[0].size();

        // UF uf(row * col + 1);

        // int dummy = row * col;

        // for (int i = 0; i < row; i++)
        // {
        //     if (board[i][0] == 'O')
        //     {
        //         uf.unite(i * col, dummy);
        //     }
            
        //     if (board[i][col - 1] == 'O')
        //     {
        //         uf.unite(i * col + col - 1, dummy);
        //     }
        // }
        
        // for (int j = 0; j < col; j++)
        // {
        //     if (board[0][j] == 'O')
        //     {
        //         uf.unite(j, dummy);
        //     }
            
        //     if (board[row - 1][j] == 'O')
        //     {
        //         uf.unite((row - 1) * col + j, dummy);
        //     }
        // }
        
        // vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // for (int i = 1; i < row - 1; i++)
        // {
        //     for (int j = 1; j < col - 1; j++)
        //     {
        //         if (board[i][j] == 'O')
        //         {
        //             for (int k = 0; k < 4; k++)
        //             {
        //                 int x = i + direction[k][0];

        //                 int y = j + direction[k][1];

        //                 if (board[x][y] == 'O')
        //                 {
        //                     uf.unite(x * col + y, i * col + j);
        //                 }
        //             }
        //         }
        //     }
        // }
        
        // for (size_t i = 1; i < row - 1; i++)
        // {
        //     for (size_t j = 1; j < col - 1; j++)
        //     {
        //         if (!uf.isConnected(dummy, i * col + j))
        //         {
        //             board[i][j] = 'X';
        //         }
        //     }
        // }
    }
};
// @lc code=end

