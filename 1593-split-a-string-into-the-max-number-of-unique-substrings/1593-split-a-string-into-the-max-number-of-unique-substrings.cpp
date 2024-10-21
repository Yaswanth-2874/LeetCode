class Solution {
    // BRUTE FORCE AND CHECK ALL THE POSSIBILITIES USING PICK AND DONT PICK
    // RETURN MAX
    // I AM NOT SATISFIED WITH THE CODE QUALITY, I WILL RESOLVE THE SAME PROBLEM IN BETTER QUALITY
    int maxCount;
    
    int findMaxSplits(string& s, unordered_set<string>& splitSubstrings, string& current, int index) {
        if(index == s.size()) {
            if(current.size())
                return INT_MIN;
            for(auto& st : splitSubstrings)
                cout<<st<<" ";
            cout<<endl;
            maxCount = max(maxCount, (int)splitSubstrings.size());
            return 0;
        }
        
        int divide , dontDivide;
        current.push_back(s[index]);
        
        if(splitSubstrings.find(current) == splitSubstrings.end()) {
            splitSubstrings.insert(current);
            string newCurrent = "";
            divide = 1 + findMaxSplits(s, splitSubstrings, newCurrent, index+1);
            splitSubstrings.erase(current);
        } 
        
        dontDivide = findMaxSplits(s, splitSubstrings, current, index+1);
        current.pop_back();
        
        return max(divide, dontDivide);
    }
public:
    int maxUniqueSplit(string s) {
        string current = "";
        maxCount = 1;
        unordered_set<string> splitSubstrings;
        findMaxSplits(s, splitSubstrings, current, 0);
        return maxCount;
    }
};