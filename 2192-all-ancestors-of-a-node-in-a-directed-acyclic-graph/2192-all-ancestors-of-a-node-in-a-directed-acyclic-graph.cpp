class Solution {
    void dfs(vector<vector<int>>& graph, int sourceNode, int currentNode, vector<vector<int>>& ans) {
        for(auto& destinations : graph[currentNode])
            if((ans[destinations].empty() || ans[destinations].back() != sourceNode)) {
                ans[destinations].push_back(sourceNode);
                dfs(graph, sourceNode, destinations, ans);
            }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<vector<int>> ans(n);
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        for(int i = 0; i < n; i++)
            dfs(graph, i, i, ans);
        return ans;
    }
};