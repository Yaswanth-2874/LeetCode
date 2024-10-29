class Solution {
    vector<pair<int, int>> directions;
    int rows, columns;
    vector<vector<int>> memo;
    
    int findMaxPath(int x, int y, int prevVal, vector<vector<int>>& grid) {
        if(x >= rows || y >= columns || x < 0 || y < 0 || grid[x][y] <= prevVal)
            return 0;
        if(memo[x][y] != -1)
            return memo[x][y];
        
        int maxDistance = 0;
        
        for(auto& [xInc, yInc] : directions) {
            maxDistance = max(maxDistance, findMaxPath(x + xInc, y + yInc, grid[x][y], grid));
        }
        
        return memo[x][y] = 1 + maxDistance;
    }
    
public:
    int maxMoves(vector<vector<int>>& grid) {
        directions = {{-1, 1}, {0, 1}, {1, 1}};
        rows = grid.size();
        columns = grid[0].size();
        int maxMoves = 0;
        memo = vector<vector<int>> (rows, vector<int> (columns, -1));
        
        for(int i = 0; i < rows; i++) {
            int moves = findMaxPath(i, 0, -1, grid);
            maxMoves = max(moves-1, maxMoves);
        }
        return maxMoves;
    }
};