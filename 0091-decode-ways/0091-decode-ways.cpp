class Solution {
    int decode(string& s, vector<int>& memo, int index = 0) {
        if(index == s.size())
            return 1;

        if(s[index] == '0')
            return 0;
        if(memo[index] != -1)
            return memo[index];
        int numWays = decode(s, memo, index+1);
        if(index + 1 < s.size() && (s[index] == '1' || (s[index] == '2' && s[index+1] <= '6')))
            numWays += decode(s, memo, index+2);
        return memo[index] = numWays;
    }
public:
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return decode(s, memo);
    }
};