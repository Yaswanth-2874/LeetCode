class Solution {
    int primsAlgorithm(vector<vector<int>>& points) {
        int minimumCost = 0;
        int connections = points.size() - 1, point = 0;
        priority_queue<pair<int, int>> pq;
        vector<int> visited(points.size(), false);
        visited[0] = 0;
        
        while(connections--) {
            visited[point] = true;
            for(int i = 0; i < points.size(); i++) {
                if(!visited[i])
                    pq.push({-(abs(points[point][0] - points[i][0]) + abs(points[point][1] - points[i][1])), i});
            }
            while(pq.size() && visited[pq.top().second]) 
                pq.pop();
            minimumCost -= pq.top().first;
            point = pq.top().second;
            
        }
        return minimumCost;        
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      return primsAlgorithm(points);
    }
};