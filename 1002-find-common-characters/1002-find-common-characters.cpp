class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> globalFreq(26,0);
        for(auto& letter : words[0]) {
            globalFreq[letter-'a']++;
        }
        
        for(auto& word : words) {
            vector<int> currentFreq(26,0);
            for(auto& letter : word) {
                currentFreq[letter-'a']++;
            }
            for(int i = 0; i < 26; i++) {
                globalFreq[i] = min(globalFreq[i],currentFreq[i]);
            }
        }
        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            if(globalFreq[i]) {
                string st = "";
                st += i + 'a';
                ans.push_back(st);
                globalFreq[i]--;
                i--;
            }
            
        }
        return ans;
    }
};