class Solution {
    // PREPARING FOR MSTS LMAO
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for(int currentAmount = 1; currentAmount <= amount; currentAmount++) {
            for(int coin : coins) {
                if(coin > currentAmount || dp[currentAmount - coin] == INT_MAX)
                    continue;
                int cost = dp[currentAmount - coin] + 1;
                dp[currentAmount] = min(cost, dp[currentAmount]);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};