class Solution {
    // SOLVING USING DIJKSTRAS ALGORITHM FOR NOW, WILL COMEBACK LATER FOR OTHER SHORTEST PATH ALGORITHMS
    #define pii pair<int, int>
    int n;
    int distanceThreshold;
    
    int findNeighboursFromShortestDistances(vector<int>& distancesFromCity, int sourceCity) {
        int numberOfNeighbours = 0;
        for(int currentCity = 0; currentCity < n; currentCity++) {
            if(currentCity == sourceCity)
                continue;
            numberOfNeighbours += distancesFromCity[currentCity] <= distanceThreshold;
        }
        // cout<<"Neighbours for "<<sourceCity<<" : "<<numberOfNeighbours<<endl;
        return numberOfNeighbours;
    }
    
    int findNeighbours(vector<vector<pii>>& cityRoutes, int sourceCity) {
        vector<int> distancesFromCity(n, 1e9);
        distancesFromCity[sourceCity] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, sourceCity});
        
        while(!pq.empty()) {
            auto [travelledDistance, sourceCity] = pq.top();
            pq.pop();
            
            if(travelledDistance > distancesFromCity[sourceCity])
                continue;
            
            for(auto& [destinationCity, travelDistance] : cityRoutes[sourceCity]) {
                if(travelDistance + travelledDistance < distancesFromCity[destinationCity]) {
                    distancesFromCity[destinationCity] = travelDistance + travelledDistance;
                    pq.push({travelDistance + travelledDistance, destinationCity});
                }
            }
        }
        
        return findNeighboursFromShortestDistances(distancesFromCity, sourceCity);
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        this->n = n;
        this->distanceThreshold = distanceThreshold;
        vector<vector<pii>> cityRoutes(n);
        
        for(auto& routeInfo : edges) {
            int city1 = routeInfo[0];
            int city2 = routeInfo[1];
            int distanceBetweenCities = routeInfo[2];
            
            cityRoutes[city1].push_back({city2, distanceBetweenCities});
            cityRoutes[city2].push_back({city1, distanceBetweenCities});
        }
        int minNeighbours = 1e9;
        int cityWithMinNeighbours = -1;
        
        for(int currentCity = 0; currentCity < n; currentCity++) {
            int currentCityNeighbours = findNeighbours(cityRoutes, currentCity);
            if(minNeighbours >= currentCityNeighbours) {
                minNeighbours = currentCityNeighbours;
                cityWithMinNeighbours = currentCity;
            }
        }
        
        return cityWithMinNeighbours;
    }
};