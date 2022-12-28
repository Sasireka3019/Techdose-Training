class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<vector<int>> graph, int node, int target)
    {
        temp.push_back(node);
        if(node == target)
            res.push_back(temp);
        else
        {
            for(int child : graph[node])
            {
                dfs(graph, child, target);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, graph.size()-1);
        return res;
    }
};
