class Solution {
public:
    long long minimumSteps(string s) {
        long long minSteps = 0;
        int lastZeroIndex = -1;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0')
                lastZeroIndex = i;
        }
        
        for(int i = lastZeroIndex - 1; i >= 0; i--) {
            if(s[i] == '1') 
                minSteps += lastZeroIndex-- - i;
        }
        
        return minSteps;
    }
};

// 1101011100
// 0123456789