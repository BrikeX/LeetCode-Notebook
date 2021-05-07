/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        // 回溯算法
        if (n == 1)
        {
            return 1;
        }
        
        vector<vector<string>> result;

        vector<string> board(n, string(n, '.'));

        backTracking(n, 0, board, result);

        return result.size();
    }

    void backTracking(int& n, int row, vector<string>& board, vector<vector<string>>& result)
    {
        if (row == n)
        {
            result.push_back(board);

            return;
        }
        
        for (size_t col = 0; col < n; col++)
        {
            if (!isValid(board, row, col, n))
            {
                continue;
            }
            
            board[row][col] = 'Q';

            backTracking(n, row + 1, board, result);

            board[row][col] = '.';
        }
    }

    bool isValid(vector<string>& board, int row, int col, int& n)
    {
        // 检查列
        for (size_t i = 0; i < n; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }
        
        // 检查右上方
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        
        // 检查左上方
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

