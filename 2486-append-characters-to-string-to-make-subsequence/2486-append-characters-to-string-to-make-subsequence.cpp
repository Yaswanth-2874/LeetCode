class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans = t.size();
        int index = 0;
        
        for(char ch : s) {
            if(ch == t[index]) {
                index++;
            }
            if(!ans) return 0;
        }
        return ans-index;
    }
};