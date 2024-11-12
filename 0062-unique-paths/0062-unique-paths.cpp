class Solution {
    // Space Optimised
public:
    int uniquePaths(int m, int n) {
        vector<int> lastRow(n+1, 0);
        vector<int> currentRow(n+1, 0);
        lastRow[n-1] = 1;
        
        for(int row = m-1; row >= 0; row--) {
            for(int col = n-1; col >= 0; col--) {
                currentRow[col] = max(currentRow[col], lastRow[col]+currentRow[col+1]);
            }
            for(int i = 0; i < lastRow.size(); i++) {
                lastRow[i] = currentRow[i];
                currentRow[i] = 0;
            }
        }
        
        return lastRow[0];
    }
};