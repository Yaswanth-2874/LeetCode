class Solution {
    #define pii pair<int, int>
    int calculateMaxDelay(vector<vector<pii>>& graph, int source, int n) {
        vector<int> timeTaken(n+1, 1e9);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, source});
        timeTaken[source] = 0;
        timeTaken[0] = -1; //F* THIS ONE BASED INDEXING, ALWAYS NEED TO DEBUG CAUSE I CANT REMEMBER S*
        
        while(!pq.empty()) {
            auto [timeCost, source] = pq.top();
            pq.pop();
            
            if(timeCost > timeTaken[source])
                continue;
            for(auto& [destination, extraTime] : graph[source]) {
                if(timeCost + extraTime < timeTaken[destination]) {
                    timeTaken[destination] = timeCost + extraTime;
                    pq.push({timeCost + extraTime, destination});
                }
            }
            
        }
        
        // for(int time : timeTaken)
        //     cout<<time<<" ";
        int minMaxTime = *max_element(timeTaken.begin(), timeTaken.end());
        return minMaxTime == 1e9 ? -1 : minMaxTime;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> graph(n + 1);
        for(auto& travelInfo : times) {
            int sourceNode = travelInfo[0];
            int destinationNode = travelInfo[1];
            int timeTaken = travelInfo[2];
            
            graph[sourceNode].push_back({destinationNode, timeTaken});
        }
        
        return calculateMaxDelay(graph, k, n);
    }
};