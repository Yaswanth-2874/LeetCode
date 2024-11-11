class Solution {
    // Bottom up successful, next target is to space optimise this
    
    // This step seems easy as i can see that i am only using dp of nextCol, i can simply convert it into a array with only 2 cols
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        
        vector<vector<int>> dp(rows, vector<int> (2, 0));
        
        for(int col = columns - 2; col >= 0; col--) {
            int nextCol = col + 1;
            
            for(int row = 0; row < rows; row++) {
                int topRight = INT_MIN;
                int middleRight = grid[row][nextCol];
                int bottomRight = INT_MIN;
                
                if(row - 1 >= 0) {
                    topRight = grid[row - 1][nextCol];
                } if(row + 1 < rows) {
                    bottomRight = grid[row + 1][nextCol];
                }
                
                int currentValue = grid[row][col];
                int maxDistance = 0;
                
                if(topRight > currentValue) 
                    maxDistance = max(maxDistance, 1+dp[row-1][1]);
                if(bottomRight > currentValue) 
                    maxDistance = max(maxDistance, 1+dp[row+1][1]);
                if(middleRight > currentValue)
                    maxDistance = max(maxDistance, 1+dp[row][1]);
                
                dp[row][0] = maxDistance;
            }
            
            for(int row = 0; row < rows; row++) {
                dp[row][1] = dp[row][0];
            }
        }
        
        int maxDistance = 0;
        for(int i = 0; i < rows; i++) {
            maxDistance = max(maxDistance, dp[i][0]);
        }
        
        return maxDistance;        
    }
};