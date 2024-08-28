class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0, maxContentedChildren = 0;
        
        for(int num : g) {
            while(left < s.size() && s[left] < num)
                left++;
            if(left >= s.size())
                return maxContentedChildren;
            maxContentedChildren++;
            left++;
        }
        return maxContentedChildren;
    }
};