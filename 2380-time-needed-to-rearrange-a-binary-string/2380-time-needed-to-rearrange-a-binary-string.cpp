class Solution {
    bool replace(string& s) {
        bool present = false;
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == '0' && s[i+1] == '1') {
                swap(s[i],s[i+1]);
                i++;
                present = true;
            }
        }
        return present;
    }
public:
    int secondsToRemoveOccurrences(string s) {
        int ans = 0;
        while(replace(s)) {
            ans++;
        }
        return ans;
    }
};