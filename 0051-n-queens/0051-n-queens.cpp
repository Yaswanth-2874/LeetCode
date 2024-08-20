class Solution {
    int n;
    vector<vector<string>> ans;
    unordered_map<int, int> rows, cols, diag1, diag2;
    
    bool canPlaceQueen(vector<string>& board, int x, int y) {
        if(rows[x] >= 1)
            return false;
        if(cols[y] >= 1)
            return false;
        if(diag1[x+y] >= 1)
            return false;
        return diag2[x-y] < 1;
    }
    
    void placeQueen(vector<string>& board, int row = 0) {
        if(row >= n) {
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(canPlaceQueen(board, row, i)) {
                // cout<<"Can place queen at "<<row<<" , "<<i<<endl;
                board[row][i] = 'Q';
                rows[row]++;
                cols[i]++;
                diag1[row+i]++;
                diag2[row-i]++;
                
                placeQueen(board, row+1);
                
                board[row][i] = '.';
                rows[row]--;
                cols[i]--;
                diag1[row+i]--;
                diag2[row-i]--;
            }
        }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        string row = "";
        for(int i = 0; i < n; i++)
            row.push_back('.');
        
        vector<string> board(n, row);
        placeQueen(board);
        
        return ans;
    }
};