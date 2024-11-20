class Solution {
    // testing my new macro
    #define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
public:
    int takeCharacters(string s, int k) {
        freqMap(char, s);
        int n = s.size();
        map<int, int> deleteFreq;
        if(freq['a'] < k || freq['b'] < k || freq['c'] < k)
            return -1;
        
        int left = 0;
        int maxWindowSize = 0;

        for(int right = 0; right < n; right++) {
            deleteFreq[s[right]]++;
            int remainingFreq = freq[s[right]] - deleteFreq[s[right]];
            while(left <= right && remainingFreq < k) {
                deleteFreq[s[left++]]--;
                remainingFreq = freq[s[right]] - deleteFreq[s[right]];
            }
          
            maxWindowSize = max(maxWindowSize, right - left + 1);            
        }
        return n - maxWindowSize;
    }
};