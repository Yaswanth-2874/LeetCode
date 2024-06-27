class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int commonElement = edges[0][0];
        
        for(int i = 0; i < 2; i++) {
            if(edges[1][i] == commonElement)
                return commonElement;
        }
        return edges[0][1];
    }
};