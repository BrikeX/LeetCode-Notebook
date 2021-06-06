/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    int board_size = 9;

    void solveSudoku(vector<vector<char>>& board) {
        // 回溯算法
        backTracking(board, 0, 0);
    }

    bool backTracking(vector<vector<char>>& board, int row, int col)
    {
        if (col == board_size)
        {
            return backTracking(board, row + 1, 0);
        }
        
        if (row == 9)
        {
            return true;
        }
        
        if (board[row][col] != '.')
        {
            return backTracking(board, row, col + 1);
        }
        
        for (char c = '1'; c <= '9'; c++)
        {
            if (!isValid(board, row, col, c))
            {
                continue;
            }
            
            board[row][col] = c;

            if (backTracking(board, row, col + 1))
            {
                return true;
            }
            
            board[row][col] = '.';
        }
        
        return false;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for (int i = 0; i < board_size; i++)
        {
            if (board[row][i] == c)
            {
                return false;
            }
            
            if (board[i][col] == c)
            {
                return false;
            }
            
            if (board[(row/3)*3 + i/3][(col/3)*3 + i%3] == c)
            {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

