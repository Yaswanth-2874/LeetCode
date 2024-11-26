class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegrees(n);
        
        for(auto& edge : edges) {
            // int source = edge[0];
            int destination = edge[1];
            
            indegrees[destination]++;
        }
        int champion = -1;
        for(int i = 0; i < n; i++) {
            if(indegrees[i] == 0) {
                if(champion != -1)
                    return -1;
                champion = i;
            }
        }
        
        return champion;
    }
};