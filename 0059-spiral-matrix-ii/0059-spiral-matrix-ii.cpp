class Solution {
    void fillElements(vector<vector<int>>& ans, int bottom,int right, int left = 0, int top = 0, int current = 1) {
        
        if(left > right || top > bottom)
            return;
        for (int i = left; i <= right; i++) {
             ans[top][i] = current++;
        }
        for (int i = top + 1; i <= bottom; i++) {
             ans[i][right] = current++;
        }
        if(right != left)
            for (int i = right - 1; i >= left; i--)
                ans[bottom][i] = current++;
        if(top != bottom)
            for(int i = bottom - 1; i >= top + 1; i--)
                ans[i][left] = current++;

        return fillElements(ans, bottom-1, right-1, left+1, top+1, current);
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n, 0));
        fillElements(ans, n-1, n-1);
        return ans;
    }
};