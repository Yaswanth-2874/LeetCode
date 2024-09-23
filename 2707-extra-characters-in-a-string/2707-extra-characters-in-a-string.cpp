class Solution {
    vector<int> memo;
public:
    int solve(string& s, unordered_set<string>& dictWords, int index) {
        if (index >= s.size()) 
            return 0;
        if(memo[index] != -1)
            return memo[index];
        
        string current = "";
        int minExtra = s.size();
        
        for(int cutIdx = index; cutIdx < s.size(); cutIdx++) {
            current.push_back(s[cutIdx]);
            int currExtra = (dictWords.count(current))? 0 : current.size();
            int nextExtra = solve(s, dictWords, cutIdx + 1);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        return memo[index] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dictWords(dictionary.begin(), dictionary.end());
        memo = vector<int> (s.size(), -1);
        
        int ans = solve(s, dictWords, 0);
        return ans;  
    }
};