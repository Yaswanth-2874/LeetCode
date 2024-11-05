class Solution {
    //Overall time Complexity is bounded by O(n * L)
    string generateRLE(string& original) {
        //Time complexity of this part is O(L) where L is the length of original string
        string RLE = "";
        int index = 0;
        char prev = '#';
        int freq = 1;
        
        for(auto& ch : original) {
            if(ch == prev) {
                freq++;
            } else {
                if(prev != '#') {
                    RLE.push_back(freq + '0');
                    RLE.push_back(prev);
                }
                freq = 1;
            }
            prev = ch;
        }
        
        RLE.push_back(freq + '0');
        RLE.push_back(prev);
        
        return RLE;
    }
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string previous = countAndSay(n-1);
        int startIndex = 0;
        char prev = '#';
        
        return generateRLE(previous);        
    }
};