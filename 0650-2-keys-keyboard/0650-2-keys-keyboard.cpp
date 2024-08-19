class Solution {
    vector<vector<int>> memo;
    int calculateMinSteps(int n, int current = 1, int copy = 1) {
        if(current > n)
            return 1e9;
        if(current == n)
            return 0;
        if(memo[current][copy] != -1)
            return memo[current][copy];
        
        int dontCopy = 1 + calculateMinSteps(n, current + copy, copy);
        int copied = 2 + calculateMinSteps(n, current * 2, current);
        
        return memo[current][copy] = min(copied, dontCopy);
    }
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        
        memo = vector<vector<int>> (n+1, vector<int> (n+1, -1));
        return 1 + calculateMinSteps(n);
    }
};
