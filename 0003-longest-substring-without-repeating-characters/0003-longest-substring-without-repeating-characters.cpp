class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> freq;
        int maxSize = 0;
        
        for(int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            while(freq[s[right]] == 2) {
                freq[s[left++]]--;
            }
            maxSize = max(maxSize, right - left + 1);
        }
        return maxSize;
    }
};