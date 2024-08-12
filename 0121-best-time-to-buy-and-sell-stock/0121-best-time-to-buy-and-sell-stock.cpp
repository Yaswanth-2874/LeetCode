class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = INT_MAX;
        int profit = 0;
        for(int num : prices) {
            currMin = min(currMin, num);
            profit = max(profit, -currMin + num);
        }
        return profit;
    }
};