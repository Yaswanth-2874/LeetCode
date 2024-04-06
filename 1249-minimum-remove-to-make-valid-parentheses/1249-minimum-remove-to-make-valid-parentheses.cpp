class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int opening = 0, totalOpening = 0;
        
        for(char ch : s) {
            opening += ch == '(';
            totalOpening += ch == '(';
            if(!opening && ch == ')') {
                continue;
            }
            opening -= ch == ')';
            ans.push_back(ch);
        }
        if(!opening)
            return ans;
        
        int index = 0;
        totalOpening -= opening;
        
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == '(' && totalOpening > 0)
                totalOpening--;
            else if (ans[i] == '(')
                continue;
            ans[index++] = ans[i];
        }
        
        return ans.substr(0, index);
        
        
    }
};