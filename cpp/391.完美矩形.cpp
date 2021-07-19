/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> vertex = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};

        vector<pair<int, int>> points(4);

        set<pair<int, int>> memo;

        int actual_area = 0;

        for (auto &&rectangle : rectangles)
        {
            vertex[0] = min(vertex[0], rectangle[0]);

            vertex[1] = min(vertex[1], rectangle[1]);

            vertex[2] = max(vertex[2], rectangle[2]);

            vertex[3] = max(vertex[3], rectangle[3]);

            actual_area += (rectangle[2] - rectangle[0]) * 
                           (rectangle[3] - rectangle[1]);
            
            points[0] = make_pair(rectangle[0], rectangle[1]);

            points[1] = make_pair(rectangle[0], rectangle[3]);

            points[2] = make_pair(rectangle[2], rectangle[1]);

            points[3] = make_pair(rectangle[2], rectangle[3]);

            for (auto &&point : points)
            {
                if (memo.find(point) != memo.end())
                {
                    memo.erase(point);
                }
                else
                {
                    memo.insert(point);
                }
            }
        }

        int expected_area = (vertex[2] - vertex[0]) * (vertex[3] - vertex[1]);

        if (actual_area != expected_area)
        {
            return false;
        }
        
        if (memo.size() != 4)
        {
            return false;
        }

        for (int i = 0; i < 3; i += 2)
        {
            for (int j = 1; j < 4; j += 2)
            {
                pair<int, int> p = make_pair(vertex[i], vertex[j]);

                if (!memo.count(p))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
// @lc code=end

