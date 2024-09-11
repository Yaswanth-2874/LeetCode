class Solution {
public:
    int minBitFlips(int start, int goal) {
        int bitFlips = 0;
        int bitIndex = 0;
        
        while(bitIndex < 32) {
            int startBitValue = (1 << bitIndex) & start;
            int goalBitValue = (1 << bitIndex) & goal; 
            if(startBitValue != goalBitValue)
                bitFlips++;
            bitIndex++;
        }
        
        return bitFlips;
    }
};