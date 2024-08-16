class Solution {
    int rows, columns;
    int findPaths(vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo, int i = 0, int j = 0) {
        if(i == rows - 1 && j == columns - 1)
            return !obstacleGrid[i][j];
        if(i >= rows || j >= columns || obstacleGrid[i][j])
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int left = findPaths(obstacleGrid, memo, i, j+1);
        int right = findPaths(obstacleGrid, memo, i+1, j);
        
        return memo[i][j] = left + right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->rows = obstacleGrid.size();
        this->columns = obstacleGrid[0].size();
        
        vector<vector<int>> memo(rows , vector<int> (columns, -1));        
        return findPaths(obstacleGrid, memo);
    }
};