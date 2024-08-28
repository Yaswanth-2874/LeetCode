class Solution {
    vector<vector<int>> memo;
    
    int calculateWays(int balance, vector<int>& coins, int left = 0) {
        if(balance == 0)
            return memo[balance][left] = 1;
        if(balance < 0)
            return 0;
        if(memo[balance][left] != -1)
            return memo[balance][left];
        
        int totalWays = 0;
        
        for(int i = left; i < coins.size(); i++) {
            totalWays += calculateWays(balance - coins[i], coins, i);
        }
        return memo[balance][left] = totalWays;        
    }   
public:
    int change(int amount, vector<int>& coins) {
        memo = vector<vector<int>> (amount + 1, vector<int> (coins.size(), -1));
        return calculateWays(amount, coins);
    }
};