class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //BRUTE FORCE APPROACH
        map<int, int> freq;
        for(int num : nums) {
            if(num > 0) freq[num]++;
        }
        int toReturn = 1;
        for(auto it : freq) {
            if(it.first != toReturn) return toReturn;
            toReturn++;
        }
        return toReturn;
    }
};