class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int num : arr)
            freq[num]++;
        for(int num : target)
            freq[num]--;
        for(auto it : freq) {
            if(it.second)
                return false;
        }
        return true;
    }
};