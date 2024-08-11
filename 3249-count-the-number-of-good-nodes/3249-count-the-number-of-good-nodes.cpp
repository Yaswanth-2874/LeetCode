class Solution {
    void dfs(vector<vector<int>>& trees, vector<int>& size, int& ans, int node = 0) {
        if(node != 0 && trees[node].size() == 1) {
            ans++;
            size[node] = 1;
            return;
        }
        size[node] = 1;
        unordered_map<int, int> childSize;
        
        for(int neighbours : trees[node]) {
            if(size[neighbours] == -1) {
                dfs(trees, size, ans, neighbours);
                size[node] += size[neighbours];
                childSize[size[neighbours]]++;
            }
        }
        if(childSize.size() == 1)
            ans++;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> trees(n);
        for(auto& edge : edges) {
            trees[edge[0]].push_back(edge[1]);
            trees[edge[1]].push_back(edge[0]);
        }
        vector<int> size(n, -1);
        int ans = 0;
        
        dfs(trees, size, ans);
        return ans;
    }
};