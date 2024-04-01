class Solution {
public:
    int lengthOfLastWord(string s) {
        int prevCount = 0;
        int count = 0;
        s.push_back(' ');
        for(auto ch : s) {
            if(ch == ' ' && count) {
               prevCount = count;
               count = 0;
           }
            else if(ch != ' ')
                count++;
        }
        return prevCount;
    }
};