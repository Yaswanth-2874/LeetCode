class Solution {
    // Since only capital and small letters are considered, i can perform check operations in O(56) = O(1) time
    bool checkSatisfied(unordered_map<char, int>& freqTarget, unordered_map<char, int>& freqObtained) {
        for(auto& [character, freq] : freqTarget) {
            if(freqObtained.find(character) == freqObtained.end() || freqObtained[character] < freq)
                return false;
        }
        
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqTarget;
        for(char& ch : t) {
            freqTarget[ch]++;
        }
        
        unordered_map<char, int> freqObtained;  
        int left = 0;
        int minWindowSize = s.size();
        int minLeftIndex = -1;
        int minRightIndex = -1;
        
        for(int right = 0; right < s.size(); right++) {
            freqObtained[s[right]]++;
            
            while(checkSatisfied(freqTarget, freqObtained)) {
                int currentWindowSize = right - left + 1;
                // cout<<"Current Window Size is "<<currentWindowSize<<endl;
                if(currentWindowSize <= minWindowSize) {
                    minLeftIndex = left;
                    minRightIndex = right;
                    // cout<<left<<" <--> "<<right<<endl;
                    minWindowSize = currentWindowSize;
                }
                freqObtained[s[left++]]--;
            }
            // cout<<left<<" & "<<right<<endl;
        }
        
        if(minLeftIndex == -1)
            return "";
        string minWindowString = s.substr(minLeftIndex, minWindowSize);
        return minWindowString;
    }
};