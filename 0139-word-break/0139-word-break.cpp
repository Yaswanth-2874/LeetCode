class Solution {
    unordered_set<string> words;
    unordered_map<int, unordered_map<string, int>> memo;
    
    bool canWordBreak(string& original, int i, string current) {
        if(!current.size() && i >= original.size())
            return true;
        if(i >= original.size())
            return false;
        if(memo[i][current]) {
            if(memo[i][current] > 0)
                return true;
            return false;
        }
        
        current.push_back(original[i]);
     
        bool breakWord = false, dontBreakWord = false;
        
        if(words.find(current) != words.end()) {
            breakWord = canWordBreak(original, i+1, "");
        }
        dontBreakWord = canWordBreak(original, i+1, current);
        
        bool result = breakWord || dontBreakWord;
        memo[i][current] = result ? 1 : -1;
        
        return breakWord || dontBreakWord;    
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(string word : wordDict) {
            words.insert(word);
        }
        
        return canWordBreak(s, 0, "");
    }
};
