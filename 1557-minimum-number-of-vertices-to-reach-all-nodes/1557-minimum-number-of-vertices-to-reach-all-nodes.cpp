class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        vector<int> ans;
        
        for(auto edge : edges) {
            indegree[edge[1]]++;
        }
        
        for(int i = 0; i < n; i++) {
            if(!indegree[i])
                ans.push_back(i);
        }
        return ans;
    }
};