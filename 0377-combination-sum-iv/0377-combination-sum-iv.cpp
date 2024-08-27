class Solution {
    vector<int> memo;
    int findPossible(vector<int>& nums, int target, int sum = 0) {
        if(sum > target)
            return 0;
        if(sum == target)
            return 1;
        if(memo[sum] != -1)
            return memo[sum];
        
        int possibilities = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            possibilities += findPossible(nums, target, sum);
            sum -= nums[i];
        }
        
        return memo[sum] = possibilities;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        memo = vector<int>(target, -1);
        return findPossible(nums, target);
    }
};