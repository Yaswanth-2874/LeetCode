class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> restoredMatrix(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int minVal = min(rowSum[i], colSum[j]);
                restoredMatrix[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -=  minVal;
                colSum[j] -= minVal;
            }
        }
        return restoredMatrix;
    }
};