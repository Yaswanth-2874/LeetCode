class Solution {
    int mod = 1e9 + 7;
    int n;
    int memo[100001][2][3];
    
    long long countWays(int day, int totalAbsents, int consecutiveLates) {
        if(day >= n)
            return 1;
        
        if(memo[day][totalAbsents][consecutiveLates] != -1)
            return memo[day][totalAbsents][consecutiveLates];
        
        long long ways = 0;
        
        if(totalAbsents < 1) 
            ways += countWays(day + 1, totalAbsents + 1, 0);
        if(consecutiveLates < 2)
            ways += countWays(day + 1, totalAbsents, consecutiveLates + 1);
        ways += countWays(day + 1, totalAbsents, 0);
        
        ways %= mod;
        
        memo[day][totalAbsents][consecutiveLates] = ways;
        return ways;
    }

public:
    int checkRecord(int n) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
    
        return countWays(0, 0, 0);
    }
};
