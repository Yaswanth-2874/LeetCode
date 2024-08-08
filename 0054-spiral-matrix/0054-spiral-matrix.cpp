class Solution {
    int m, n;
    void findSpiralOrder(vector<int>& ans, vector<vector<int>>& matrix, int top, int left, int bottom, int right) {
        // cout<<top<<" "<<bottom<<" "<<left<<" "<<right<<endl;
        if(top > bottom || left > right)
            return;
        
        for(int j = left; j <= right; j++)
            ans.push_back(matrix[top][j]);
        
        for(int i = top + 1; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        
        if(top != bottom)
            for(int j = right - 1; j >= top; j--)
                ans.push_back(matrix[bottom][j]);
        
        if(left != right)
            for(int i = bottom - 1; i > top; i--)
                ans.push_back(matrix[i][left]);
        
        findSpiralOrder(ans, matrix, top + 1, left + 1, bottom - 1, right - 1);    
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int totalVisited = 0;
        m = matrix.size() - 1;
        n = matrix[0].size() - 1;
        findSpiralOrder(ans, matrix, 0, 0, m, n);
        return ans;
    }
};