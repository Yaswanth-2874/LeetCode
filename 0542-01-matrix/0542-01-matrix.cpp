class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> ans(m, vector<int> (n, -1));
        int elementsLeft = m * n;
        
        queue<pair<int, int>> coordinates;
        
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    elementsLeft--;
                    coordinates.push({i+1, j});
                    coordinates.push({i-1, j});
                    coordinates.push({i, j+1});
                    coordinates.push({i, j-1});
                }
            }
        }
        
        int level = 1;
        while(!coordinates.empty() && elementsLeft) {
            int size = coordinates.size();
            
            while(size--) {
                auto [x, y] = coordinates.front();
                coordinates.pop();
                // cout<<x<<y
                if(x < 0 || y < 0 || x >= m || y >= n || ans[x][y] != -1)
                    continue;
                ans[x][y] = level;
                elementsLeft--;
                coordinates.push({x+1, y});
                coordinates.push({x-1, y});
                coordinates.push({x, y+1});
                coordinates.push({x, y-1});
            }
            level++;
        }
        
        return ans;
    }
};