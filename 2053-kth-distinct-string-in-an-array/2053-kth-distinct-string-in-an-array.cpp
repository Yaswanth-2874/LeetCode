class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> set, dups;
        for(auto& str : arr) {
            if(set.find(str) == set.end()) 
                set.insert(str);
            else
                dups.insert(str);
        }
        
        for(auto& str : arr) {
            if(dups.find(str) == dups.end())
                k--;
             if(!k)
                return str;
        }
        return "";
    }
};