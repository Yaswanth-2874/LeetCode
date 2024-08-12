class Solution {
    int findGreatestValidDay(vector<int>& days, int target) {
        int left = 0, right = days.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(days[mid] > target)
                right = mid - 1;
            else if (days[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return left;
    }
    
    int findMinCost(vector<int>& days, vector<int>& costs, vector<int>& memo, int i = 0) {
        if(i >= days.size())
            return 0;
        if(memo[i] != -1)
            return memo[i];
        
        int dayCost = costs[0] + findMinCost(days, costs, memo, i + 1);
        int weekCost = costs[1] + findMinCost(days, costs, memo, findGreatestValidDay(days, days[i] + 7));
        int monthCost = costs[2] + findMinCost(days, costs, memo, findGreatestValidDay(days, days[i] + 30));
        
        return memo[i] = min(min(dayCost, weekCost), monthCost);
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size() , -1);
        return findMinCost(days, costs, memo);
    }
};