class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0, right = 0, length = 0;
        
        while(right < s.size()) {
            freq[s[right]]++;
            while(freq[s[right]] == 2) {
                freq[s[left++]]--;
            }
            length = max(length, right-left+1);
            right++;
        }
        
        return length;
    }
};