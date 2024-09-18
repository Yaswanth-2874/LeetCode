class Solution {
     vector<int> findTopologicalSort(vector<vector<int>>& graph, vector<int>& indegree) {
        int courses = graph.size();
        queue<int> q;
        vector<int> topoSort;
        
        for(int i = 0; i < courses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            int parent = q.front();
            q.pop();
            topoSort.push_back(parent);
            for(int child : graph[parent]) {
                indegree[child]--;
                if(indegree[child] == 0)
                    q.push(child);
            }
        }
         if(topoSort.size() != indegree.size())
             topoSort.clear();
         
        return topoSort;        
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        
        for(auto& prerequisite : prerequisites) {
            int parent = prerequisite[1];
            int child = prerequisite[0];
            
            graph[parent].push_back(child);
            indegree[child]++;
        }
        return findTopologicalSort(graph, indegree);
    }
};