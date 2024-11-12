class Solution {
    unordered_map<int, int> rows, cols, diag1, diag2;
    vector<vector<string>> validPositions;
    
    bool canPlaceQueen(int row, int col) {
        if(rows[row] || cols[col] || diag1[row + col] || diag2[row - col])
            return false;
        return true;
    }
    
    void placeQueen(int row, int n, vector<string>& board) {
        if(row == n) {
            validPositions.push_back(board);
        }
        for(int col = 0; col < n; col++) {
            if(canPlaceQueen(row, col)) {
                board[row][col] = 'Q';
                rows[row] = 1;
                cols[col] = 1;
                diag1[row + col] = 1;
                diag2[row - col] = 1;
                placeQueen(row+1, n, board);
                rows[row]  = 0;
                board[row][col] = '.';
                cols[col] = 0;
                diag1[row + col] = 0;
                diag2[row - col] = 0;
            }
        }
    }
     
public:
    vector<vector<string>> solveNQueens(int n) {
        string boardRow = "";
        for(int i = 0; i < n; i++)
            boardRow.push_back('.');
        
        vector<string> board(n, boardRow);
        placeQueen(0, n, board);
        
        return validPositions;        
    }
};