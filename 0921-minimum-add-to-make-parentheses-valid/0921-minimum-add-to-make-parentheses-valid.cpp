class Solution {
    // OPTIMISATION IN O(1) SPACE
public:
    int minAddToMakeValid(string s) {
        int openingBrackets = 0;
        int requiredAdditions = 0;
        for(auto& bracket : s) {
            if(bracket == '(')
                openingBrackets++;
            else {
                if(openingBrackets)
                    openingBrackets--;
                else
                    requiredAdditions++;
            }
        }
        // FOR ALL OPENING BRACKETS ADD ONE CLOSING BRACKET
        return requiredAdditions + openingBrackets;
    }
};