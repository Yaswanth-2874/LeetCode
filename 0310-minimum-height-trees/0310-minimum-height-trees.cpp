class Solution {    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        vector<vector<int>> trees(n);
        vector<int> degrees(n);
        vector<bool> visited(n);
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            trees[u].push_back(v);
            trees[v].push_back(u);
            degrees[u]++;
            degrees[v]++;
        }
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(degrees[i] == 1)
                q.push(i);
        }
        int poppedElements = 0;
        while(!q.empty()) {
            int size = q.size();
            if(poppedElements >= n-2)
                break;
            
            while(size--) {
                int node = q.front();
                q.pop();
                // cout<<"Deleted : "<<node<<endl;
                for(int neighbour : trees[node]) {
                    degrees[neighbour]--;
                    if (degrees[neighbour] == 1) {
                        q.push(neighbour);
                    }
                }
                poppedElements++;
            }
        }
        // cout<<degrees[2];
        int ans = q.front();
        q.pop();
        if(!q.empty())
            return {ans, q.front()};
        return {ans};
        
    }
};