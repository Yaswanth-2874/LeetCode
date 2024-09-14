class Solution {
    int m, n;
    vector<pair<int, int>> directions;
    
    void visitIsland(vector<vector<char>>& grid, int i, int j) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == '0')
            return;
        
        // cout<<grid[i][j]<<" : ";
        // cout<<"Visited : "<<i<<", "<<j<<endl;
        grid[i][j] = '0';
        
        for(auto& [x, y] : directions) {
            visitIsland(grid, i+x, j+y);
        }        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int islands = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    visitIsland(grid, i , j);
                }
            }
        }
        return islands;
    }
};