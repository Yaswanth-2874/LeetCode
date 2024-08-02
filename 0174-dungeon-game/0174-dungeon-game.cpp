class Solution {
    int findMinHp(vector<vector<int>>& dungeon, vector<vector<int>>& memo, int i = 0, int j = 0) {
        if(i == memo.size() - 1 && j == memo[i].size() - 1)
            return memo[i][j] = dungeon[i][j] >= 0 ? 1 : abs(dungeon[i][j]) + 1;
        
        if(i >= memo.size() || j >= memo[i].size())
            return INT_MAX;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int rightDirection = findMinHp(dungeon, memo, i, j+1);
        int leftDirection = findMinHp(dungeon, memo, i+1, j);
        
        int ans = min(leftDirection, rightDirection) - dungeon[i][j];
        return memo[i][j] = ans <= 0 ? 1 : ans;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> memo(dungeon.size(), vector<int> (dungeon[0].size(), -1));
        int ans = findMinHp(dungeon, memo);
        // for(auto list : memo) {
        //     for(auto num : list)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};