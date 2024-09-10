class Solution {
public:
    int numSquares(int n) {
        if(n < 4)
            return n;
        
        vector<int> minSquares(n+1);
        for(int i = 0; i < 4; i++)
            minSquares[i] = i;
        
        for(int i = 4; i <= n; i++) {
            int root = sqrt(i);
            int moves = i;
            
            for(int j = root; j >= 1; j--) {
                int squareNumber = j * j;
                moves = min(minSquares[i - squareNumber], moves);
            }
            minSquares[i] = moves + 1;
        }
        
        return minSquares[n];
    }
};