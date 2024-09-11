class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        
        for(int index = n - 2; index >= 0; index--) {
            for(int jumpSize = nums[index]; jumpSize >= 1; jumpSize--) {
                int landingPosition = index + jumpSize;
                if( landingPosition >= n - 1|| dp[landingPosition] == true) {
                    dp[index] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};