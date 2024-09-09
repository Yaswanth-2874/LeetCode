class Solution {
    vector<int> memo;
public:
    Solution () {
        memo = vector<int> (20, -1);
    }
    int numTrees(int n) {
        if(n <= 1)
            return 1;
        int ans = 0;
        if(memo[n] != -1)
            return memo[n];
        for(int i = 1; i <= n; i++) {
            int placeLeft = numTrees(i - 1);
            int placeRight = numTrees(n - i);
            ans += placeLeft * placeRight;
        }
        return memo[n] = ans;
    }
};