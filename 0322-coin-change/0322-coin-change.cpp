class Solution {
    vector<int> memo;
    
    int findMinCoins(vector<int>& coins, int amount) {
        if(amount < 0)
            return -1;
        if(amount == 0)
            return 0;
        
        if(memo[amount] != -2)
            return memo[amount];
        
        int minCoins = INT_MAX;
    
        for(int i = 0; i < coins.size(); i++) {
            int currCoins = findMinCoins(coins, amount - coins[i]);
            if(currCoins != -1)
                minCoins = min(currCoins + 1, minCoins);
        }
        
        return memo[amount] = minCoins == INT_MAX ? -1 : minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memo = vector<int>(amount + 1, -2);
  
        return findMinCoins(coins, amount);
    }
};
