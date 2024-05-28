class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> cost;
        for(int i = 0; i < s.size(); i++) {
            int difference = abs(s[i] - t[i]);
            cost.push_back(difference);
        }
        // for(int num : cost) cout<<num<<" ";
        int left = 0, currentCost = 0, maxLen = 0;
        for(int right = 0; right < cost.size(); right++) {
            currentCost += cost[right];
            // cout<<left<<" "<<right<<endl;
            while(currentCost > maxCost) {
                currentCost -= cost[left++];
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};