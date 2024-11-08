class Solution {
    int findKValue(int xorValue, int maxBit) {
        int k = 0;
        for(int i = 0; i < maxBit; i++) {
            int bitValue = 1 << i;
            
            //If bit of xorValue is 0, then k th bit can be one
            if((bitValue & xorValue) == 0) {
                k += bitValue;
            }
        }
        
        return k;
    }
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorValue = 0;
        
        for(int& num : nums)
            xorValue ^= num;
        
        int index = nums.size() - 1;
        vector<int> ans;
        
        while(index >= 0) {
            int k = findKValue(xorValue, maximumBit);
            ans.push_back(k);
            xorValue ^= nums[index--];
        }
        
        return ans;
    }
};