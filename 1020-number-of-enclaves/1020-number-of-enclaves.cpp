class Solution {
    int m, n;
    vector<pair<int, int>> directions;
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0 || !grid[i][j])
            return 0;
        int nonEnclaveCount = 1;
        grid[i][j] = 0;
        
        for(auto& [x, y] : directions) {
            nonEnclaveCount += dfs(grid, i+x, j+y);
        }
        return nonEnclaveCount;
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int totalCount = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                totalCount += grid[i][j] == 1;
        }
        int nonEnclaveCount = 0;
        
        for(int i = 0; i < m; i++) {
            if(grid[i][0])
                nonEnclaveCount += dfs(grid, i, 0);
            if(grid[i][n-1])
                nonEnclaveCount += dfs(grid, i, n-1);
        }
        
        for(int i = 1; i < n - 1; i++) {
            if(grid[0][i])
                nonEnclaveCount += dfs(grid, 0, i);
            if(grid[m-1][i])
                nonEnclaveCount += dfs(grid, m-1, i);
        }
        return totalCount - nonEnclaveCount;
    }
};