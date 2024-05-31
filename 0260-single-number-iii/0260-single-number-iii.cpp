class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        vector<int> ans;
        
        for(auto& it : freq) {
            if(it.second == 1) ans.push_back(it.first);
        }
        return ans;
    }
};
