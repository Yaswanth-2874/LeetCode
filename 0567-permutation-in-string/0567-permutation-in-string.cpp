class Solution {
    bool isPermutation(vector<int>& s1Characters, vector<int>& s2Characters) {
        for(int i = 0; i < 26; i++) {
            if(s1Characters[i] != s2Characters[i])
                return false;
        }
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        vector<int> s1Characters(26);
        vector<int> s2Characters(26);
        
        int size = s1.size();
        int windowSize = size;
        for(char& ch : s1) {
            int currentCharacter = ch - 'a';
            s1Characters[currentCharacter]++;
        }
        for(int i = 0; i < windowSize; i++) {
            int currentCharacter = s2[i] - 'a';
            s2Characters[currentCharacter]++;
        }
        
        int left = 0, right = windowSize;
        while(right < s2.size()) {
            if(isPermutation(s1Characters, s2Characters))
                return true;
            int leftChar = s2[left++] - 'a';
            int rightChar = s2[right++] - 'a';
            s2Characters[leftChar]--;
            s2Characters[rightChar]++;
        }
        return isPermutation(s1Characters, s2Characters);
    }
};