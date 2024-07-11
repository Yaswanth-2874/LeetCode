class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> lastOpeningBracketPos;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                lastOpeningBracketPos.push(i);
            else if(s[i] == ')') {
                int first = lastOpeningBracketPos.top();
                reverse(s.begin() + first, s.begin() + i);
                lastOpeningBracketPos.pop();
            }
        }
        string ans = "";
        for(char ch : s) {
            if(ch != '(' && ch != ')')
                ans.push_back(ch);
        }
        return ans;
    }
};