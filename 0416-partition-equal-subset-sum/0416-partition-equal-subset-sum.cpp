class Solution {
    vector<vector<int>> memo; 
    bool solve(vector<int>& nums, int totalSum, int left = 0) {
        if(!totalSum)
            return true;
        if(totalSum < 0)
            return false;
        if(left >= nums.size())
            return false;
        if(memo[left][totalSum] != -1)
            return memo[left][totalSum];
        
        bool considerElement = solve(nums, totalSum - nums[left], left+1);
        bool dontConsiderElement = solve(nums, totalSum, left+1);
            
        if(considerElement || dontConsiderElement)
            return memo[left][totalSum] = true;
        
        return memo[left][totalSum] = false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        
        for(int num : nums)
            totalSum += num;
        
        if(totalSum % 2)
            return false;
        
        totalSum /= 2;
        
        memo = vector<vector<int>>(nums.size(), vector<int>(totalSum + 1, -1));
        return solve(nums, totalSum);
    }
};