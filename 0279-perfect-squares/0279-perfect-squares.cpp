class Solution {
public:
    int numSquares(int n) {
        if(n < 4)
            return n;
        double root = sqrt(n);
        int largestSquareRoot = floor(root);
     
        int minMoves = n;
        for(int i = largestSquareRoot; i >= 1; i--) {
            int currentMoves = n/(i*i);
            currentMoves += numSquares(n % (i*i));
            minMoves = min(minMoves, currentMoves);
        }
        return minMoves;
    }
};