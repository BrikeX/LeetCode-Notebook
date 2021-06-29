/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // 双指针算法
        vector<vector<int>> result;

        if (firstList.empty() || secondList.empty())
        {
            return result;
        }
        
        int i = 0, j = 0;

        while (i < firstList.size() && j < secondList.size())
        {
            if (secondList[j][1] >= firstList[i][0] && firstList[i][1] >= secondList[j][0])
            {
                result.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
            }

            if (secondList[j][1] < firstList[i][1])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        
        return result;
    }
};
// @lc code=end

