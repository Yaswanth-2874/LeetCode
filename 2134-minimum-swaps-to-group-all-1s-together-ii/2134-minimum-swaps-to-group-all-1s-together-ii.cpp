class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = 0;
    
        for(int num : nums)
            totalOnes += num == 1;
        
        int currentZeroes = 0;
        int left = 0, right = 0;
        
        for(right = 0; right < totalOnes; right++) {
            currentZeroes += nums[right] == 0;
        }
        int minZeroes = currentZeroes;
        
        while(left < nums.size()) {
            right %= nums.size();
            currentZeroes -= nums[left++] == 0;
            currentZeroes += nums[right++] == 0;
            
            minZeroes = min(minZeroes, currentZeroes);
        }
        return minZeroes;
    }
};