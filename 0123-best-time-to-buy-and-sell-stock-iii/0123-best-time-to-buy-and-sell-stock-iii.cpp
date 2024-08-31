class Solution {
    vector<vector<int>> memo;
    int calcProfit(vector<int>& prices, int day, int transactionsLeft) {
        if(day >= prices.size())
            return 0;
        
        if(!transactionsLeft)
            return 0;
        
        if(memo[day][transactionsLeft] != -1)
            return memo[day][transactionsLeft];
        
        int skipDay = calcProfit(prices, day+1, transactionsLeft);
        int dontSkipDay = 0;
        
        if(transactionsLeft % 2 == 0) //Bought Stock
            dontSkipDay = calcProfit(prices, day+1, transactionsLeft - 1) - prices[day];
        else //Sold Stock
            dontSkipDay = calcProfit(prices, day+1, transactionsLeft - 1) + prices[day];
        
        return memo[day][transactionsLeft] =  max(skipDay, dontSkipDay);       
    }
public:
    int maxProfit(vector<int>& prices) {
        memo = vector<vector<int>> (prices.size(), vector<int> (5, -1));
        return calcProfit(prices, 0, 4);
    }
};