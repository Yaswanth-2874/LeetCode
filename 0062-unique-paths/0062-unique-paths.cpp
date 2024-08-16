class Solution {
    int findNumberOfPaths(vector<vector<int>>& memo, int m, int n, int i = 0, int j = 0) {
        if(i == m - 1 && j == n - 1) 
            return memo[i][j] = 1;
        
        if(i >= m || j >= n)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int left = findNumberOfPaths(memo, m, n, i, j+1);
        int down = findNumberOfPaths(memo, m, n, i+1, j);
        
        return memo[i][j] = left+down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int> (n, -1));
        return findNumberOfPaths(memo, m, n);
    }
};