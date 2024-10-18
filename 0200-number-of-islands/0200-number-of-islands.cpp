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
    
    bool mergeNeighbours(int x, int y, vector<vector<char>>& grid, DisjointSet &ds) {
        if(x >= n || x < 0 || y >= m || y < 0 || grid[x][y] == '0' || grid[x][y] == 'V')
            return false;
        int gridAddress = x * m + y;
        grid[x][y] = 'V';
        for(auto& [xInc, yInc] : directions) {
            if(mergeNeighbours(x + xInc, y + yInc, grid, ds)) {
                int newGridAddress = (x + xInc) * m + (y + yInc);
                ds.unionMerge(gridAddress, newGridAddress);
            }
        }
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        DisjointSet ds(n * m);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
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