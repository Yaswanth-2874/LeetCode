class Solution {
    int checkSetBits(vector<int>& candidates, int bitPos) {
        int bit = 1 << bitPos;
        int setBits = 0;
        
        for(int& candidate : candidates) {
            if(bit & candidate)
                setBits++;
        }
        
        return setBits;
    } 
public:
    int largestCombination(vector<int>& candidates) {
        int largestCombinationSize = 0;
        
        for(int bitPos = 0; bitPos < 32; bitPos++) {
            int setBits = checkSetBits(candidates, bitPos);
            largestCombinationSize = max(largestCombinationSize, setBits);
        }
        
        return largestCombinationSize;
    }
};