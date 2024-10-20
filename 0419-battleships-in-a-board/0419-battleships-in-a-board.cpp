class Solution {
    // LETS START WITH BASIC DFS  
    int m, n;
    vector<pair<int, int>> directions;
    void count(int x, int y, vector<vector<char>>& board) {
        if(x >= m || y >= n || x < 0 || y < 0 || board[x][y] == '.')
            return;
        
        board[x][y] = '.';
        for(auto& [xInc, yInc] : directions)
            count(x+xInc, y+yInc, board);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        directions = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
        int battleShips = 0;
        m = board.size();
        n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                if(board[i][j] == 'X') {
                    count(i, j, board);
                    battleShips++;
                }
        }
        return battleShips;
    }
};