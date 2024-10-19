class Solution {
    class DisjointSet {
    public:
        vector<int> parent, size;
        DisjointSet(int n) {
            size.resize(n, 1);
            for(int i = 0; i < n; i++) {
                parent.push_back(i);
            }
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
                parent[parentB] = parentA;
                size[parentA] += size[parentB];
            } else {
                parent[parentA] = parentB;
                size[parentB] += size[parentA];
            }
            return true;
        }        
    };
    int n;
    vector<pair<int, int>> directions;
    int maxSize = 0;
    void makeItIsland(int x, int y, vector<vector<int>>& grid, DisjointSet &ds) {
        int currentSize = 1;
        unordered_set<int> parents;
        
        for(auto& [xInc, yInc] : directions) {
            int newX = x + xInc;
            int newY = y + yInc;
            
            if(newX >= n || newX < 0 || newY >= n || newY < 0 || grid[newX][newY] == 0)
                continue;
            
            int newAddress = newX * n + newY;
            int parent = ds.findParent(newAddress);
            if(parents.find(parent) == parents.end())
                currentSize += ds.size[parent];
            parents.insert(parent);
        }
        maxSize = max(maxSize, currentSize);
    }
    void merge(int x, int y, vector<vector<int>>& grid, DisjointSet &ds) {
        int oldAddress = x * n + y;
        for(auto& [xInc, yInc] : directions) {
            int newX = x + xInc;
            int newY = y + yInc;
            
            if(newX >= n || newX < 0 || newY >= n || newY < 0 || grid[newX][newY] == 0)
                continue;
            
            int newAddress = newX * n + newY;
            ds.unionMerge(oldAddress, newAddress);
        }
        int parentNode = ds.findParent(oldAddress);
        maxSize = max(maxSize, ds.size[parentNode]);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        maxSize = 0;
        DisjointSet ds(n * n);
        directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j])
                    merge(i, j, grid, ds);
            }
        }
                
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j])
                    makeItIsland(i, j, grid, ds);
            }
        }
        
        return maxSize;
    }
};

// For this, i could do the following
    // First maintain all the sizes of each island
    // Then traverse through ocean(0) and keep track of maxIslandSize if i change that 0 to one
    // I can find size by using disjointSet, find parent of 1 and using its parent, i can calculate size (sum of sizes of two parents + 1)
    // Demn, this question didnt feel so hard, it felt like medium level
// After coding this question, i feel like we only need to implement the solution, the question is relatively simple, only code is too large