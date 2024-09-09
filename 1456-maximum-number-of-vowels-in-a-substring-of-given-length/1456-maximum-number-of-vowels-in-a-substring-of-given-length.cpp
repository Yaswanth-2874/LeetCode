class Solution {
    bool isVowel(char& ch) {
        string vowels = "aeiou";
        for(char& vowel : vowels)
            if(vowel == ch)
                return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int maxVowel = 0, currentVowels = 0;
        for(int i = 0; i < k; i++) {
            if(isVowel(s[i]))
                currentVowels++;
        }
        maxVowel = currentVowels;
        int left = 0, right = k;
        while(right < s.size()) {
            currentVowels -= isVowel(s[left++]);
            currentVowels += isVowel(s[right++]);
            maxVowel = max(maxVowel, currentVowels);
        }
        return maxVowel;
    }
};