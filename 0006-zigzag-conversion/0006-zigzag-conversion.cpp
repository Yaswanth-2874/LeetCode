class Solution {
public:
    string convert(string s, int numRows) {
         if (numRows == 1 || s.size() <= numRows) {
            return s;
        }
        
        string zigzagConverted = "";
        vector<string> pattern(numRows);
        int row = 0;
        bool goingDown = true;
        
        for(char& ch : s) {
            pattern[row].push_back(ch);
            
            if((goingDown && row + 1 >= numRows) || (!goingDown && row == 0))
                goingDown = !goingDown;
            if(goingDown)
                row++;
            if(!goingDown)
                row--;
        }

        for(auto& st : pattern)
            zigzagConverted += st;
        return zigzagConverted;        
    }
};
