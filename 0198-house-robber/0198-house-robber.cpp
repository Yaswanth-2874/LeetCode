class Solution {
    int solve(vector<int>& nums, vector<int>& memo, int currentHouse) {
        if(currentHouse >= nums.size()) return 0;
        
        if(memo[currentHouse] == -1) {
            return memo[currentHouse] = max(
                nums[currentHouse] + solve(nums, memo, currentHouse+2),
                solve(nums, memo, currentHouse+1)
            );
        }
        return memo[currentHouse];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, memo, 0);
    }
};