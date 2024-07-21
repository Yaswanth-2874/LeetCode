class Solution {
    int dp(vector<int>& memo, vector<int>& nums, int currentHouse = 0) {
        if(currentHouse >= memo.size())
            return 0;
        if(memo[currentHouse] == -1) {
            memo[currentHouse] = max(
                nums[currentHouse] + dp(memo, nums, currentHouse + 2),
                dp(memo, nums,currentHouse + 1)
            );
                return memo[currentHouse];
        }
        return memo[currentHouse];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return dp(memo, nums);
    }
};