class Solution {
    vector<vector<char>> board;
    bool isValidBox(int x, int y) {

        vector<int> nums(10, 0);
        for(int i = x; i < x + 3; i++) {
            for(int j = y; j < y + 3; j++) {
                if(board[i][j] == '.' )
                    continue;
                int num = board[i][j] - '0';
                // cout<<num<<endl;
                if(nums[num]++)
                    return false;
            }
        }
        return true;
    }
    
    bool isValidCol(int x, int y) {
        vector<int> nums(10, 0);
        for(int i = 0; i < 9; i++) {
            if(board[i][y] == '.' )
                    continue;
            int num = board[i][y] - '0';
                if(nums[num]++)
                    return false;
        }
        return true;
    }
    
    bool isValidRow(int x, int y) {
        vector<int> nums(10, 0);
        for(int i = 0; i < 9; i++) {
            if(board[x][i] == '.' )
                    continue;
            int num = board[x][i] - '0';
                if(nums[num]++)
                    return false;
        }
        return true;
    }
    
   
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        this->board = board;
        
        for(int i = 0; i < 9; i++) {
            if(!isValidCol(0, i))
                return false;
        }
        for(int i = 0; i < 9; i++) {
            if(!isValidRow(i, 0))
                return false;
        }
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3)
                if(!isValidBox(i, j))
                    return false;
        }
        return true;
    }
};