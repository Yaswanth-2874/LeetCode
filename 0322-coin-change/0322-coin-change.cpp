class Solution {
    vector<int> memo;
    
    int findMinCoins(int amount, vector<int>& coins) {
        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;
        if(memo[amount] != -2)
            return memo[amount];
        
        int minCoins = INT_MAX;
        for(int i = coins.size() - 1; i >= 0; i--) {
            int requiredCoins = findMinCoins(amount - coins[i], coins);
            if(requiredCoins == -1)
                continue;
            minCoins = min(minCoins, 1 + requiredCoins);
        }
        return memo[amount] = minCoins == INT_MAX ? -1 : minCoins;        
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memo = vector<int> (amount + 1, -2);
        if(amount == 0)
            return 0;
        return findMinCoins(amount, coins);
    }
};