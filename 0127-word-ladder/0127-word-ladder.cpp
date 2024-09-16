class Solution {
    int compareWords(string& word1, string& word2) {
        int wordSize = word1.size();
        int unequalLetterCount = 0;
        
        for(int i = 0; i < wordSize; i++) {
            unequalLetterCount += word1[i] != word2[i]; 
        }
        
        return unequalLetterCount;
    }
    
    int findShortestSequenceLength(vector<vector<int>>& sequences, vector<bool>& visited, int targetIndex, int startIndex) {
        queue<int> q;
        int sequenceLength = 0;
        q.push(startIndex);
        
        while(!q.empty()) {
            int size = q.size();
            sequenceLength++;
            
            while(size--) {
                int front = q.front();
                visited[front] = true;
                q.pop();
                cout<<front<<" ";
                
                if(targetIndex == front)
                    return sequenceLength;
                
                for(auto& child : sequences[front]) {
                    if(!visited[child])
                        q.push(child);
                }
            }
            cout<<endl;
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int words = wordList.size();
        vector<vector<int>> sequences(words + 1);
        int endWordIndex = -1, startWordIndex = -1;
        
        for(int i = 0; i < words; i++) {
            if(endWordIndex == -1 && wordList[i] == endWord)
                endWordIndex = i;
            if(startWordIndex == -1 && wordList[i] == beginWord)
                startWordIndex = i;
            
        }
        
        startWordIndex = startWordIndex == -1 ? 0 : startWordIndex + 1;
        
        if(endWordIndex == -1)
            return 0;
        endWordIndex++;

        for(int i = 0; i < words; i++) {
            int unequalLetterCount = compareWords(beginWord, wordList[i]);
            // cout<<beginWord<<" : ";
            if(unequalLetterCount == 1) {
                sequences[0].push_back(i+1);
                // cout<<wordList[i];
            }
        }
        
        for(int i = 0; i < words; i++) {
            cout<<wordList[i]<<" : ";
            for(int j = 0; j < words; j++) {
                int unequalLetterCount = compareWords(wordList[i], wordList[j]);
                if(unequalLetterCount == 1) {
                    sequences[i+1].push_back(j+1);
                    cout<<wordList[j]<<" ";
                }
            }
            cout<<endl;
        }
        
       for(int i = 0; i < words + 1; i++) {
           cout<<i<<" : ";
           for(int j = 0; j < sequences[i].size(); j++) {
               cout<<sequences[i][j]<<" ";
           }
           cout<<endl;
       }
        
//         cout<<"Started at "<<startWordIndex<<endl;
//         cout<<"To End at "<<endWordIndex<<endl;
        
        vector<bool> visited(words + 1, false);
        return findShortestSequenceLength(sequences, visited, endWordIndex, startWordIndex);   
    }
};