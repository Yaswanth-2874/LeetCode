class Solution {
    vector<vector<int>> memo;
    
    int findLongestLength(string& text1, string& text2, int index1, int index2) {
        if(index1 == text1.size() || index2 == text2.size())
            return 0;
        if(memo[index1][index2] != -1)
            return memo[index1][index2];
        
        if(text1[index1] == text2[index2])
            return 1 + findLongestLength(text1, text2, index1 + 1, index2 + 1);
        int skip1 = findLongestLength(text1, text2, index1 + 1, index2);
        int skip2 = findLongestLength(text1, text2, index1, index2 + 1);
        
        return memo[index1][index2] = max(skip1, skip2);
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo = vector<vector<int>> (text1.size(), vector<int>(text2.size(), -1));
        return findLongestLength(text1, text2, 0, 0);
    }
};