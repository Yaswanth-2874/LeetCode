class Solution {
public:
    int minLength(string s) {
        stack<char> remainingLetters;
        
        for(auto& ch : s) {
            if(ch == 'B') {
                if(!remainingLetters.empty() && remainingLetters.top() == 'A')
                    remainingLetters.pop();
                else
                    remainingLetters.push('B');
            } else if(ch == 'D') {
                if(!remainingLetters.empty() && remainingLetters.top() == 'C')
                    remainingLetters.pop();
                else
                    remainingLetters.push('D');
            } else {
                remainingLetters.push(ch);
            }
        }
        
        return (int)remainingLetters.size();
    }
};