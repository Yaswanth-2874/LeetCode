class Solution {
public:
    bool rotateString(string s, string goal) {
        for (int i = 0; i < s.size(); i++) {
            char front = s[0]; 
            s = s.substr(1);
            s.push_back(front);
            if(s == goal)
                return true;
        }
        
        return false;
    }
};