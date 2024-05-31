class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        for(int num : nums) {
            xorResult ^= num;
        }
        int initialguess = 1;
        while(true) {
            if(initialguess & xorResult) break;
            initialguess <<= 1;
        }
        int secondValue = 0;
        for(int num : nums ) {
            if(num & initialguess)
                secondValue ^= num;
        }
        int firstValue = xorResult ^ secondValue;
        
        return {firstValue, secondValue};
        
    }
};

