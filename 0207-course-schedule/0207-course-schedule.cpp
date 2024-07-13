class Solution {
   
    bool topologicalSort(vector<vector<int>>& graph, int vertices, vector<int>& indegree) {
        int count = 0;
        queue<int> elements;
        for(int i = 0; i < vertices; i++) {
            if(!indegree[i]) {
                elements.push(i);
            }
        }
        while(!elements.empty()) {
            int top = elements.front();
            elements.pop();
            count++;
            for(int connection : graph[top]) {
                indegree[connection]--;
                if(!indegree[connection])
                    elements.push(connection);
            }
        }
        return count == vertices;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<bool> visited(numCourses);
        vector<vector<int>> graph(numCourses);
        
        for(auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }
        
        return topologicalSort(graph, numCourses, indegree);
    }
};