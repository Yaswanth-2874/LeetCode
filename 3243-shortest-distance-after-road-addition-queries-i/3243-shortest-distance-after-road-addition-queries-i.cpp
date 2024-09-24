class Solution {
    #define pii pair<int, int>
    int dijkstra(vector<vector<int>>& graph, int n) {
        vector<int> dist(n, 1e9);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();
            
            if(distance > dist[node])
                continue;
            for(int child : graph[node]) {
                if(1 + distance > dist[child])
                    continue;
                dist[child] = 1 + distance;
                pq.push({dist[child], child});
            }
        }
        return dist[n-1];
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }
        vector<int> res;
        
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].push_back(v);
            res.push_back(dijkstra(graph, n));
        }
        
        return res;
    }
};