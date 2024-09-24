class Solution {
    void storeAllPrefixes(int num, unordered_set<int>& prefixes) {
        while(num) {
            prefixes.insert(num);
            num /= 10;
        }
    }
    int findLongestPrefix(int num, unordered_set<int>& prefixes) {
        int size = log10(num) + 1;
        while(num) {
            if(prefixes.find(num) != prefixes.end())
                return size;
            size--;
            num /= 10;
        }
        return 0;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for(int& num : arr1) {
            storeAllPrefixes(num, prefixes);
        }
        int longestPrefixSize = 0;
        for(int& num : arr2) {
            longestPrefixSize = max(longestPrefixSize, findLongestPrefix(num, prefixes));
        }
        return longestPrefixSize;
    }
};