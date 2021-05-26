/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // 有向无权图的递归算法
        vector<int> path;

        traverseGraph(graph, 0, path);

        return result;
    }

    void traverseGraph(vector<vector<int>>& graph, int node, vector<int>& path)
    {
        path.push_back(node);

        if (node == graph.size() - 1)
        {
            result.push_back(path);

            path.pop_back();

            return;
        }
        
        for (size_t i = 0; i < graph[node].size(); i++)
        {
            traverseGraph(graph, graph[node][i], path);
        }
        
        path.pop_back();
    }
};
// @lc code=end

