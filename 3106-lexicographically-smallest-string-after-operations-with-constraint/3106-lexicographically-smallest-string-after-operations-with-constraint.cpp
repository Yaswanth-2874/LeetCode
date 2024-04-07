class Solution {
public:
    string getSmallestString(string s, int k) {
        
        for(int i = 0; i < s.size(); i++) {
            int num = s[i] - 'a';
            
            if(num >= 13) {
                if(26 - num <= k) {
                    s[i] = 'a';
                    k -= 26 - num;
                }
                else {
                    s[i] -= k;
                    k = 0;
                }
            }
            else {
                if(num - k <= 0) {
                    s[i] = 'a';
                    k -= num;
                }
                else {
                    s[i] -= k;
                    k = 0;
                }
            }
            if(k == 0)
                break;
        }
        return s;
        
    }
};