class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> ans(deck.size(), 0);
        bool skip = false;
        int blanks = deck.size();
        int index = 0;
        
        while(blanks) {    
            for(int i = 0; i < deck.size(); i++) {
                if(!ans[i]){
                    if(!skip) {
                        ans[i] = deck[index++];
                        blanks--;
                    }
                    skip = !skip;
                }
            }  
        }
        return ans;
    }
};
