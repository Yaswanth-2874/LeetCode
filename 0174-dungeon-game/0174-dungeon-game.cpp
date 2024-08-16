class Solution {
    int rows, columns;
    
    int findMinHp(vector<vector<int>>& memo, vector<vector<int>>& dungeon, int i = 0, int j = 0) {
        if(i == rows - 1 && j == columns - 1)
            return dungeon[i][j] >= 0 ? 1 : abs(dungeon[i][j]) + 1;
        if(i >= rows || j >= columns)
            return 1e9;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int left = findMinHp(memo, dungeon, i, j+1);
        int down = findMinHp(memo, dungeon, i+1, j);
        
        int ans = min(left, down) - dungeon[i][j];   
        
        return memo[i][j] = ans <= 0 ? 1 : ans;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        rows = dungeon.size();
        columns = dungeon[0].size();
        vector<vector<int>> memo(rows, vector<int> (columns, -1));
        return findMinHp(memo, dungeon);
    }
};