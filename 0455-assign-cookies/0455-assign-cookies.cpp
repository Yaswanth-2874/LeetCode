class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0, maxContentedChildren = 0;
        
        for(int num : s) {
            if(left < g.size() && g[left] <= num) {
                maxContentedChildren++;
                left++;
            }
        }
        return maxContentedChildren;
    }
};