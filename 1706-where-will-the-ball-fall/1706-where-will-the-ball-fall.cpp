class Solution {
    vector<vector<int>> memo;
    int findEndCol(vector<vector<int>>& grid, int row, int col) {
        if(row >= grid.size())
            return col;
        if(col >= grid[0].size() || col < 0)
            return -1;
        if(memo[row][col] != -2)
            return memo[row][col];
        int direction = grid[row][col];
        if(col + direction >= grid[0].size() || col + direction < 0)
            return -1;
        if(grid[row][col] != grid[row][col + direction])
            return -1;
        
        return memo[row][col] = findEndCol(grid, row + 1, col + direction);
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ballLandingPositions;
        memo = vector<vector<int>> (grid.size(), vector<int> (grid[0].size(), -2));
        for(int i = 0; i < grid[0].size(); i++)
            ballLandingPositions.push_back(findEndCol(grid, 0, i));
        
        return ballLandingPositions;
    }
};