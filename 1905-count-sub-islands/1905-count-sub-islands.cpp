class Solution {
    int m, n;
    vector<vector<int>> directions;
    
    bool isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0)
            return true;
        bool ans = grid1[i][j];
        grid2[i][j] = 0;
        
        for(auto& direction: directions) {
                ans &= isSubIsland(grid1, grid2, i+direction[0], j+direction[1]);
        }
        return ans;   
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        m = grid1.size();
        n = grid1[0].size();
        int count = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1)
                    count += isSubIsland(grid1, grid2, i, j);
            }
        }
        return count;
    }
};