class Solution {
    int findMinCoins(vector<int>& coins,unordered_map<int, int>& memo, int amount) {
        if(amount < 0)
            return -1;
        if(amount == 0)
            return 0;
        
        if(memo.find(amount) != memo.end())
            return memo[amount];
        
        int minCoins = INT_MAX;
    
        for(int i = 0; i < coins.size(); i++) {
            int currCoins = findMinCoins(coins, memo, amount - coins[i]);
            if(currCoins != -1)
                minCoins = min(currCoins + 1, minCoins);
        }
        
        return memo[amount] = minCoins == INT_MAX ? -1 : minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        return findMinCoins(coins, memo, amount);
    }
};
