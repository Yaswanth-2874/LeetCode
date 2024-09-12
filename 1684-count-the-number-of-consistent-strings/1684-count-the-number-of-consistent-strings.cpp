class Solution {
    bool isConsistent(string& word, int& allowedChars) {
        for(char& ch : word) {
            if(!(allowedChars & (1 << ch - 'a')))
                return false;
        }
        return true;
    }
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allowedChars = 0;
        
        for(char& ch : allowed) {
            allowedChars |= 1 << ch - 'a';
        }
        int consistentStrings = 0;
        
        for(string& word : words) {
            consistentStrings += isConsistent(word, allowedChars);
        }
        return consistentStrings;
    }
};