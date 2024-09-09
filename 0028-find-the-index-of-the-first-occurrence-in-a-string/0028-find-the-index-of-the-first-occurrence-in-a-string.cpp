class Solution {
    vector<int> buildLps(string& needle) {
        vector<int> lps(needle.size(), 0);
        int index = 1, left = 0;
        while(index < needle.size()) {
            if(needle[left] == needle[index]) {
                lps[index++] = ++left;
            } else {
                if(left)
                    left = lps[left - 1];
                else {
                    index++;
                }
            }
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
        vector<int> lps = buildLps(needle);
        
        int i1 = 0, i2 = 0;
        while(i1 < haystack.size()) {
            if(haystack[i1] == needle[i2]) {
                i1++;
                if(++i2 == needle.size())
                    return i1 - i2;
            } else {
                if(i2)
                    i2 = lps[i2 - 1];
                else
                    i1++;
            }
        }
        return -1;
    }
};