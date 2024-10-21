class Solution {
    class DisjointSet {
        vector<int> parent, size;
        public:
        DisjointSet(int n) {
            size.resize(n, 1);
            for(int i = 0; i < n; i++)
                parent.push_back(i);
        }
        int findParent(int node) {
            if(node == parent[node])
                return node;
            return parent[node] = findParent(parent[node]);
        }
        bool unionMerge(int nodeA, int nodeB) {
            int parentA = findParent(nodeA);
            int parentB = findParent(nodeB);
            
            if(parentA == parentB)
                return false;
            
            if(size[parentA] >= size[parentB]) {
                size[parentA] += size[parentB];
                parent[parentB] = parentA;
            } else {
                size[parentB] += size[parentA];
                parent[parentA] = parentB;
            }
            return true;
        }
    };
    vector<pair<int, int>> directions;
    int n;
    void mergeAllNeighbours(int x, int y, vector<vector<int>>& grid, DisjointSet& ds) {
        int baseAddress = x * n + y;
        int waterLevel = grid[x][y];
        
        for(auto& [xInc, yInc] : directions) {
            int newX = x + xInc;
            int newY = y + yInc;
            
            if(newX >= n || newY >= n || newX < 0 || newY < 0 || grid[newX][newY] > waterLevel)
                continue;
            
            int newAddress = newX * n + newY;
            ds.unionMerge(newAddress, baseAddress);
        }
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        map<int, vector<pair<int, int>>> levelMap;
        n = grid.size();
        directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int waterLevel = grid[i][j];
                levelMap[waterLevel].push_back({i, j});
            }
        }
        DisjointSet ds(n * n);
        for(auto& [level, positions] : levelMap) {
            for(auto& [x, y] : positions) {
                mergeAllNeighbours(x, y, grid, ds);
            }
            int sourceParent = ds.findParent(0);
            int destinationParent = ds.findParent(n * n - 1); 
            if(sourceParent == destinationParent)
                return level;
        }
        return -1;
    }
};
// Damn , i could not think about this approach when i first tried it but when i went to sleep , i got this approach in my dream
// I know it sounds crazy but it is true.. I somehow dreamt of this approach and tried it and it worked