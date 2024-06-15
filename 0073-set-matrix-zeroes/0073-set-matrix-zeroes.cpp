class Solution {
    void makeZeroes(vector<int> rows, vector<int> cols, vector<vector<int>>& matrix) {
        for(int num : rows) {
            // cout<<"row : "<<num<<endl;
            for(int i = 0; i < matrix[num].size(); i++) 
                matrix[num][i] = 0;
        }
        for(int num : cols) {
            // cout<<"COL " <<num<<endl;
            for(int i = 0; i < matrix.size(); i++) 
                matrix[i][num] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> zeroRows, zeroColumns;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j =0; j < matrix[0].size(); j++) {
                if(!matrix[i][j]) {
                    zeroRows.push_back(i);
                    zeroColumns.push_back(j);
                }
            }
        }
        makeZeroes(zeroRows, zeroColumns, matrix);
    }
};