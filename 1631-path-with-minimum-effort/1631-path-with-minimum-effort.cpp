class Solution {
    #define pip pair<int, pair<int, int>>
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> distance(m, vector<int> (n, 2e9));
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({0, {0, 0}});
        distance[0][0] = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int effort = top.first;
            auto [x, y] = top.second;
            for(auto& [xInc, yInc] : directions) {
                int newX = x + xInc;
                int newY = y + yInc;
                
                if(newX < 0 || newX >= m || newY < 0 || newY >= n)
                    continue;
                int diff = max(abs(heights[x][y] - heights[newX][newY]), effort);
                if(diff >= distance[newX][newY])
                    continue;
                distance[newX][newY] = diff;
                pq.push({diff, {newX, newY}});
            }
        }
        return distance[m-1][n-1];        
    }
};