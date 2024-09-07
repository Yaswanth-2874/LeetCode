class Solution {
    unordered_map<int, int> modMap;
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(auto& times : time) {
            int modTime = times % 60;
            modMap[modTime]++;
        }
        
        int validPairs = 0;
        
        for(int times : time) {
            times %= 60;
            
            int requiredMod = 60 - times;
            requiredMod %= 60;
            
            modMap[times]--;
            validPairs += max(0, modMap[requiredMod]);
        }
        
        return validPairs;
    }
};

// 30 : 1
// 20 : 1
// 40 : 2
    
// 1
