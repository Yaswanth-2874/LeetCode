class Solution {
    int lastPositionOfCommonPrefix(string& s1, string& s2) {
        for(int i = 0; i < min(s1.size(), s2.size()); i++) {
            if(s1[i] != s2[i]) return i;
        }
        return min(s1.size(), s2.size());
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        
        for(auto& word : strs) {
            int pos = lastPositionOfCommonPrefix(common, word);
            // cout<<pos<<endl;
            common = common.substr(0, pos);
            // cout<<common<<endl;
        }
        return common;
    }
};