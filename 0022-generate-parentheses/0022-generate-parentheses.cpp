// BRUTE FORCE APPROACH - RECURSION/BACKTRACKING
class Solution {
    vector<string> ans;
    void generator(string& current, int n, int opening, int closing) {
        if(closing == n && opening == n) {
            ans.push_back(current);
            return;
        }
        
        if(opening < n) {
            current.push_back('(');
            generator(current, n, opening+1, closing);
            current.pop_back();
        }
        if(closing < opening) {
        current.push_back(')');
        generator(current, n, opening, closing+1);
        current.pop_back();
        }
    } 
public:
    vector<string> generateParenthesis(int n) {
        string current = "";
        generator(current, n, 0, 0);
        return ans;
    }
};

