class Solution {
    void dfs(vector<vector<int>>& graph,vector<bool>& visited, int source, int& nodeCount, int& edgeCount) {
        visited[source] = true;
        nodeCount++;
        edgeCount += graph[source].size();
        
        for(auto& nextNode : graph[source]) {
            if(!visited[nextNode])
                dfs(graph, visited, nextNode, nodeCount, edgeCount);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        vector<bool> visited(n);
        
        for(int i = 0; i < n; i++) {
            int nodeCount = 0, edgeCount = 0;
            if(!visited[i]) {
                dfs(graph, visited, i, nodeCount, edgeCount);
                ans += edgeCount == (nodeCount * (nodeCount - 1));
            }
        }
        return ans;
    }
};