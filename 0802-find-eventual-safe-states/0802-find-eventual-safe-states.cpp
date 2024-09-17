class Solution {
    bool isSafeNode(vector<vector<int>>& graph, vector<int>& visited, int node) {
        
        if(!graph[node].size() || visited[node] == 1)
            return true;
        if(visited[node] == -2)
            return false;
        
        visited[node] = -2;
        for(int child : graph[node]) {
            if(!isSafeNode(graph, visited, child))
                return false;
        }
        visited[node] = 1;
        
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        vector<int> safeNodes;

        
        for(int i = 0; i < graph.size(); i++) {
            bool safeNode = isSafeNode(graph, visited, i);
            if(safeNode)
                safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};