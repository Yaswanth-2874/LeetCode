class Solution {
    #define pii pair<int, int>
    #define pip pair<int, pair<int, int>>
    int n;
    
    int findMinCost(vector<vector<pii>>& flightMap, int src, int dst, int k) {
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        // COST, SOURCE, STOPS
        vector<vector<int>> minCosts(k+2, vector<int> (n, 1e9));
        pq.push({0, {src, 0}});
        minCosts[0][src] = 0;
        
        while(!pq.empty()) {
            auto bestFlight = pq.top();
            pq.pop();
            int cost = bestFlight.first;
            auto [source, stops] = bestFlight.second;
        
            if(stops > k || cost > minCosts[stops][source])
                continue;
            
            for(auto& [destination, extraCost] : flightMap[source]) {
                if(cost + extraCost < minCosts[stops + 1][destination]) {
                    minCosts[stops + 1][destination] = cost + extraCost;
                    pq.push({cost + extraCost, {destination, stops + 1}});
                }
            }
        }
        int minCost = 1e9;
        for(int stops = 0; stops <= k + 1; stops++) {
            minCost = min(minCost, minCosts[stops][dst]);
        }
        return minCost == 1e9 ? -1 : minCost;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        this->n = n;
        vector<vector<pii>> flightMap(n);
        for(auto flight : flights) {
            for(auto info : flight) {
                int source = flight[0];
                int destination = flight[1];
                int cost = flight[2];
                flightMap[source].push_back({destination, cost});                
            }
        }
        return findMinCost(flightMap, src, dst, k);
        
    }
};