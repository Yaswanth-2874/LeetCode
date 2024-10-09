class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> brackets;
        for(auto& bracket : s) {
            if(bracket == ')')
                if(!brackets.empty() && brackets.top() == '(') {
                    brackets.pop();
                    continue;
                }
            brackets.push(bracket);
        }
        return brackets.size();
    }
};