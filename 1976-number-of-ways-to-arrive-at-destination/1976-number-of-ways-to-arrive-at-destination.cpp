class Solution {
    #define pll pair<long long, long long>
    #define pii pair<int, int>
    int mod;
    
    int countMinWays(vector<vector<pii>>& graph, int n) {
        vector<pll> timeTaken(n, {LLONG_MAX, 0});
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, 0});
        timeTaken[0] = {0, 1};
        
        while(!pq.empty()) {
            auto [currentTime, source] = pq.top();
            pq.pop();
            
            if(currentTime > timeTaken[source].first)
                continue;
            
            for(auto& [destination, travelTime] : graph[source]) {                
                if(travelTime + timeTaken[source].first < timeTaken[destination].first) {
                    timeTaken[destination].first = travelTime + timeTaken[source].first;
                    timeTaken[destination].second = timeTaken[source].second;
                    pq.push({timeTaken[destination].first, destination});
                } else if(travelTime + timeTaken[source].first == timeTaken[destination].first) {
                    timeTaken[destination].second = (timeTaken[destination].second + timeTaken[source].second) % mod;
                }
            }
        }
        
        return timeTaken[n-1].second;
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        mod = 1e9 + 7;
        vector<vector<pii>> graph(n);
        
        for(auto& road : roads) {
            int source = road[0];
            int destination = road[1];
            int timeTaken = road[2];
            graph[source].push_back({destination, timeTaken});
            graph[destination].push_back({source, timeTaken});
        }
        return countMinWays(graph, n);
    }
};
