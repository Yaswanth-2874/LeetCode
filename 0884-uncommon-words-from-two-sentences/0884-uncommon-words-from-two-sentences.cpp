class Solution {
    void calculateWordFrequency(string& s, unordered_map<string, int>& wordFreq) {
        string word = "";
        for(char& ch : s) {
            if(ch == ' ') {
                wordFreq[word]++;
                word = "";
            } else  {
                word.push_back(ch);
            }
        }
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> uncommonWords;
        unordered_map<string, int> wordFreq;
        s1.push_back(' ');
        s2.push_back(' ');
        
        calculateWordFrequency(s1, wordFreq);
        calculateWordFrequency(s2, wordFreq);
        
        for(auto [word, frequency] : wordFreq) {
            if(frequency == 1)
                uncommonWords.push_back(word);
        }
        return uncommonWords;
    }
};