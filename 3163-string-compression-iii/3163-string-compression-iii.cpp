class Solution {
public:
    string compressedString(string word) {
        char prev = '#';
        int count = 1;
        string compressed = "";
        
        for(char& letter : word) {
            if(letter == prev) {
                count++;
                if(count == 9) {
                    compressed.push_back('9');
                    compressed.push_back(letter);
                    count = 0;
                }
            } else {
                if(prev != '#') {
                    if(count != 0) {
                        compressed.push_back(count + '0');
                        compressed.push_back(prev);
                    }
                    count = 1;
                }
            }
            prev = letter;
        }
        
        //Last charater would be not filled
        
        if(count != 0) {
            compressed.push_back(count + '0');
            compressed.push_back(prev);
        }
        
        return compressed;
    }
};