class Solution {
    vector<vector<int>> memo;
    int findMinDistance(string& word1, string& word2, int index1, int index2) {
        if(index1 >= word1.size())
            return word2.size() - index2;
        if(index2 >= word2.size())
            return word1.size() - index1;
        if(memo[index1][index2] != -1)
            return memo[index1][index2];
        
        if(word1[index1] == word2[index2])
            return findMinDistance(word1, word2, index1+1, index2+1);
        
        int insertCharacter = 1 + findMinDistance(word1, word2, index1+1, index2);
        int deleteCharacter = 1 + findMinDistance(word1, word2, index1, index2+1);
        int changeCharacter = 1 + findMinDistance(word1, word2, index1 + 1, index2 + 1);
        
        return memo[index1][index2] = min({insertCharacter, deleteCharacter, changeCharacter});
    }
public:
    int minDistance(string word1, string word2) {
        memo = vector<vector<int>> (word1.size(), vector<int> (word2.size(), -1));
        return findMinDistance(word1, word2, 0 , 0);
    }
};
