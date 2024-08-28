class Solution {
    int m, n;  // Variables to store the dimensions of the grids
    vector<vector<int>> directions;  // A vector to store the possible directions for traversal

    // A helper function to check if a portion of grid2 is a sub-island of grid1
    bool isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        
        // If we go out of bounds or hit water in grid2, return true since we're still on valid land or water
        if(i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0)
            return true;

        /*
        If we're still here, it means we're on land in grid2.
        Now, we check if grid1 also has land at this location.
        If grid1 has land, we continue; otherwise, we know this part is not a sub-island.
        */
        bool ans = grid1[i][j];

        // Mark the current cell in grid2 as visited by setting it to 0
        grid2[i][j] = 0;
        
        // Explore all possible directions (up, down, left, right)
        for(auto& direction: directions) {
            ans &= isSubIsland(grid1, grid2, i+direction[0], j+direction[1]);
        }
        return ans;   
    }

public:

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // Possible directions: right, left, down, up
        m = grid1.size(); 
        n = grid1[0].size(); 
        int count = 0;  // Initialize a counter for sub-islands
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // If we find land in grid2, check if it's a sub-island using the helper function
                if(grid2[i][j] == 1 && isSubIsland(grid1, grid2, i, j))
                    count++; 
            }
        }
        return count; 
    }
};