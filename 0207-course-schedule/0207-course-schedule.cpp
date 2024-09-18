class Solution {
    bool detectCycle(vector<vector<int>>& graph, vector<int>& visited, int index) {
        if(visited[index] == 1) {
            return true;
        }
        if(visited[index] == 2) {
            return false;
        }  
        visited[index] = 1;
        
        for(int child : graph[index]) {
            if(detectCycle(graph, visited, child))
                return true;
        }
        
        visited[index] = 2;
        return false;        
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);
        
        for(auto& prerequisite : prerequisites) {
            int parent = prerequisite[1];
            int child = prerequisite[0];
            
            graph[parent].push_back(child);
        }
        bool cyclePresent = false;
        for(int i = 0; i < numCourses; i++) {
            cyclePresent |= detectCycle(graph, visited, i);
        }
        return !cyclePresent;
    }
};