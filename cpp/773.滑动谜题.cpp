/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // BFS
        int row = board.size(), col = board[0].size();

        string start, target = "123450";

        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                start.push_back(board[i][j] + '0');
            }
        }
        
        vector<vector<int>> neighbor = {
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {4, 2}
        };

        queue<string> q;

        unordered_set<string> visited;

        q.push(start);

        int step = 0;

        int q_size;

        string cur_board, new_board;

        while (!q.empty())
        {
            q_size = q.size();

            for (size_t i = 0; i < q_size; i++)
            {
                cur_board = q.front();

                visited.insert(cur_board);

                q.pop();

                if (cur_board == target)
                {
                    return step;
                }
                
                int index = 0;

                for (; cur_board[index] != '0'; index++);
                
                for (int adjacent : neighbor[index])
                {
                    new_board = cur_board;

                    swap(new_board[adjacent], new_board[index]);

                    if (!visited.count(new_board))
                    {
                        q.push(new_board);
                    }   
                }
            }
            
            step++;
        }
        
        return -1;
    }
};
// @lc code=end

