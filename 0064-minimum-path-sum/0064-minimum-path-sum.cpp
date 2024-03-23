class Solution {
    vector<vector<int>> memo;
    int solve(vector<vector<int>>& grid, int row = 0, int col = 0) {
        if(row == grid.size()-1 && col == grid[0].size() - 1) 
            return memo[row][col] = grid[row][col];

        if(memo[row][col] == -1) {
            int right,down;
            
            if(col + 1 < grid[0].size()) right = solve(grid, row, col+1);
            else right = INT_MAX;
            if(row + 1 < grid.size()) down = solve(grid, row+1, col);
            else down = INT_MAX;
            
            return memo[row][col] = grid[row][col] + min(right, down);
        }
        return memo[row][col];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> row(grid[0].size(), -1);
        
        for(int i = 0; i < grid.size(); i++)
            memo.push_back(row);
    
        return solve(grid);
    }
};