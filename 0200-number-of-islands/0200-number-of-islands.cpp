class Solution {
    class DisjointSet {
        vector<int> parent, size;
        int components;
    public:
        DisjointSet(int n) {
            size.resize(n, 1);
            for(int i = 0; i < n; i++)
                parent.push_back(i);
            components = 0;
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
            
            components--;            
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
    int n, m;
    vector<pair<int, int>> directions;
    
    void mergeNeighbours(int x, int y, vector<vector<char>>& grid, DisjointSet &ds) {
        int gridAddress = x * m + y;
        for(auto& [xInc, yInc] : directions) {
            x += xInc;
            y += yInc;
            
            if(!(x >= n || x < 0 || y >= m || y < 0 || grid[x][y] == '0')) {
                int newGridAddress = x * m + y;
                ds.unionMerge(newGridAddress, gridAddress);
            }
            
            x -= xInc;
            y -= yInc;
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        DisjointSet ds(n * m);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1')
                    mergeNeighbours(i, j, grid, ds);
            }
        }
        int islands = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int address = i * m + j;
                if(grid[i][j] != '0' && ds.findParent(address) == address)
                    islands++;
            }
        }
        return islands;
    }
};