class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for(int currentAmount = 1; currentAmount <= amount; currentAmount++) {
            for(int& coin : coins) {
                int balance = currentAmount - coin;
                if(balance < 0 || dp[balance] == INT_MAX)
                    continue;
                dp[currentAmount] = min(1+dp[balance], dp[currentAmount]);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};