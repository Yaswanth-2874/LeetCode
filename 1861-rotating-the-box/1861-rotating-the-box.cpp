class Solution {
    // Cleaner submission
    
    // To simulate the effect of gravity
    void simulateGravity(int column, int rows, int columns, vector<vector<char>>& box) {
        int stonesFound = 0;
        
        for(int row = 0; row < rows; row++) {
            // If a stone is found, increase the stone count
            // If stationary obstacle is found, then place all the available stones before it one by one
            if(box[row][column] == '#') {
                stonesFound++;
                box[row][column] = '.';
            } else if(box[row][column] == '*') {
                int prevRow = row - 1;
                while(stonesFound) {
                    box[prevRow--][column] = '#';
                    stonesFound--;
                }
            }
        }
        
        int prevRow = rows - 1;
        while(stonesFound--) {
            box[prevRow--][column] = '#';
        }
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int columns = box[0].size();
        
        // To rotate the box first
        vector<vector<char>> rotatedBox(columns, vector<char> (rows, '.'));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                int requiredRow = rows - i - 1;
                rotatedBox[j][requiredRow] = box[i][j];
            }
        }
        // Rows and columns get swapped after rotation
        swap(rows, columns);
        
        // Simulate gravity for each row
        for(int column = 0; column < columns; column++) {
            simulateGravity(column, rows, columns, rotatedBox);
        }
      
        return rotatedBox;
    }
};