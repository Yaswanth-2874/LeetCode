class Solution {
    vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    int row, col;
    
    void pushIntoQueue(int i, int j, queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        for (auto direction : directions) {
            int nx = i + direction[0];
            int ny = j + direction[1];
            if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0) {
                q.push({nx, ny});
                grid[nx][ny] = 1; 
            }
        }
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1)
            return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        
        int depth = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                if (p.first == row - 1 && p.second == col - 1)
                    return depth;
                pushIntoQueue(p.first, p.second, q, grid);
            }
            depth++;
        }
        return -1;
    }
};
