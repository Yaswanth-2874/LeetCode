class Solution {
    vector<vector<int>> paths;
    void findPath(int source, int destination, vector<int>& currentPath, vector<vector<int>>& graph) {
        currentPath.push_back(source);
        if(source == destination) {
            paths.push_back(currentPath);
            return;
        }
        for(int i = 0; i < graph[source].size(); i++) { 
            findPath(graph[source][i], destination, currentPath, graph);
            currentPath.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> currentPath;
        findPath(0, graph.size() - 1, currentPath, graph);
        return paths;
    }
};