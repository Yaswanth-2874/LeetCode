class Solution {
public:
    int minOperations(vector<int>& nums) {
        int totalOperations = 0;
        unordered_map<int, int> freqCount;
        for(int num : nums)
            freqCount[num]++;
        for(auto& it : freqCount) {
            if(it.second == 1)
                return -1;
            totalOperations += ceil(it.second/3.0);
        }
        return totalOperations;
    }
};