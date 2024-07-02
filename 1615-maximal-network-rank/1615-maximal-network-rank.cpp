class Solution {
    int areCitiesConnected(int sourceCity, int destinationCity, vector<vector<int>>& roads) {
        for(auto& road : roads) {
            if(road[0] == sourceCity && road[1] == destinationCity)
                return 1;
            if(road[1] == sourceCity && road[0] == destinationCity)
                return 1;
        }
        return 0;
    }
public:
    int maximalNetworkRank(int n, vector<vector<int>>& edges) {
        vector<int> edgesCount(n);
        
        for(auto& edge : edges) {
            edgesCount[edge[0]]++;
            edgesCount[edge[1]]++;
        }
        int ans = 0;
        for(int i = 0; i < edgesCount.size(); i++) {
            for(int j = 0; j < edgesCount.size(); j++) {
                if(i != j) {
                    int networkRank = edgesCount[i] + edgesCount[j] - areCitiesConnected(i,j, edges);
                    ans = max(ans, networkRank);
                }
            }
        }
        return ans;
    }
};