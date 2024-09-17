class Solution {
    vector<int> colors;
    
    bool dfs(vector<vector<int>>& graph, int color, int index) {
        
        if(colors[index] != -1) {
            return (color == colors[index]);
        }
        
        colors[index] = color;
        bool ans = true;
        
        for(int num : graph[index]) {
            ans &= dfs(graph, !color, num);
        }
        
        return ans;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        colors = vector<int> (graph.size(), -1);
        
        bool isBipartiteGraph = true;
        
        for(int i = 0; i < graph.size(); i++) {
            if(colors[i] == -1)
                isBipartiteGraph &= dfs(graph, 0, i);
        }
        return isBipartiteGraph;
    }
};

