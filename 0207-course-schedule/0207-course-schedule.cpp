class Solution {
    bool detectCycle(vector<vector<int>>& graph, vector<int>& indegree) {
        int courses = graph.size();
        queue<int> q;
        int size = 0;
        
        for(int i = 0; i < courses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            int parent = q.front();
            q.pop();
            size++;
            
            for(int child : graph[parent]) {
                indegree[child]--;
                if(indegree[child] == 0)
                    q.push(child);
            }
        }
        return size == indegree.size();        
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);
        
        for(auto& prerequisite : prerequisites) {
            int parent = prerequisite[1];
            int child = prerequisite[0];
            
            graph[parent].push_back(child);
            inDegree[child]++;
        }
        
        return detectCycle(graph, inDegree);
        
    }
};