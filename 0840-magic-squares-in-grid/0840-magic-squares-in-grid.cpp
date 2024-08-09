class Solution {
    bool checkMagicSquare(vector<vector<int>>& grid, int left, int top) {
        vector<int> nums(10, 0);
        for(int i = top; i < top + 3; i++) {
            int sum = 0;
            for(int j = left; j < left + 3; j++) {
                sum += grid[i][j];
                if(grid[i][j] <= 0 || grid[i][j] >= 10)
                    return false;
                nums[grid[i][j]]++;
            }
            if(sum != 15)
                return false;
        }
        for(int i = 1; i < 10; i++)
            if(nums[i] != 1)
                return false;
        for(int j = left; j < left + 3; j++) {
            int sum = 0;
            for(int i = top; i < top + 3; i++)
                sum += grid[i][j];
            if(sum != 15)
                return false;
        }
        int diag1Sum = grid[top][left] + grid[top + 1][left + 1] + grid[top + 2][left + 2];
        int diag2Sum = grid[top][left + 2] + grid[top + 1][left + 1] + grid[top + 2][left];
        if(diag1Sum == diag2Sum)
            return diag1Sum == 15;
        return false;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() < 3 || grid[0].size() < 3)
            return 0;
        int count = 0;
        for(int i = 0; i < grid.size() - 2; i++) {
            for(int j = 0; j < grid[i].size() - 2; j++)
                count += checkMagicSquare(grid, j ,i);
            
        }
        return count;        
    }
};