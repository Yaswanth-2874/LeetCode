class Solution {
    unordered_set<string> words;
    vector<string> validWords;
    
    void findWords(string& original, string current, int index, string word) {
        if(index >= original.size()) {
            if(!current.size()) {
                validWords.push_back(word);
                return;
            }
            else
                return;
        }
        
        current.push_back(original[index]);
        
        bool isValid = words.find(current) != words.end();
        findWords(original, current, index+1, word);
        if(isValid) {
            word += current;
            if(index + 1 < original.size())
                word.push_back(' ');
            findWords(original, "", index+1, word);
        }
        
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto& word : wordDict) {
            words.insert(word);
        }
    
        findWords(s, "", 0, "");
        return validWords;
    }
};