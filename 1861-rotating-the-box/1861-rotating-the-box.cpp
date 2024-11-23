class Solution {
    // easy question but i was testing wrong, i didnt rotate properly and i was wondering where my logic went wrong :(
    
    void fixRows(int column, int rows, int columns, vector<vector<char>>& box) {
        int stonesBefore = 0;
        for(int row = 0; row < rows; row++) {
            if(box[row][column] == '#') {
                stonesBefore++;
                box[row][column] = '.';
            } else if(box[row][column] == '*') {
                int prevRow = row - 1;
                // cout<<"Testing before previous platforms"<<endl;
                while(stonesBefore) {
                    box[prevRow--][column] = '#';
                    stonesBefore--;
                }
                // cout<<"Test successful"<<endl;
            }
        }
        
        // cout<<"Stones before are "<<stonesBefore<<endl;
        int prevRow = rows - 1;
        // cout<<"Testing for last rows in column "<<column<<endl;
        // cout<<"Row value starts from "<<prevRow<<endl;
        while(stonesBefore--) {
            box[prevRow--][column] = '#';
            // cout<<"Entering row value "<<prevRow<<endl;
        }
        // cout<<"Test successful"<<endl;
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int columns = box[0].size();
        cout<<rows<<" "<<columns<<endl;
        
        vector<vector<char>> rotatedBox(columns, vector<char> (rows, '.'));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                int requiredRow = rows - i - 1;
                rotatedBox[j][requiredRow] = box[i][j];
            }
        }
        swap(rows, columns);
        
        for(int column = 0; column < columns; column++) {
            fixRows(column, rows, columns, rotatedBox);
        }
      
        return rotatedBox;
    }
};