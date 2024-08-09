class Solution {
    int calculateNumSquares(int n, vector<int>& memo) {
        if(memo[n] != -1)
            return memo[n];
        if(n < 4)
            return memo[n] = n;
        
        double root = sqrt(n);
        int largestSquareRoot = floor(root);
     
        int minMoves = n;
        for(int i = largestSquareRoot; i >= 1; i--) {
            int currentMoves = n/(i*i);
            currentMoves += calculateNumSquares(n % (i * i), memo);
            minMoves = min(minMoves, currentMoves);
        }
        return memo[n] = minMoves;
    }
public:
    int numSquares(int n) {
        vector<int> memo(n+1, -1);
        return calculateNumSquares(n, memo);
    }
};