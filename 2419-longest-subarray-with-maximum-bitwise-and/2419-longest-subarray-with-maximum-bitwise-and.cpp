class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = 0, streak = 1;
        int maxSubarrays = 0;
        for(int num : nums) {
            if(maxValue < num) {
                maxValue = num;
                maxSubarrays = streak = 1;
            } else if (maxValue == num) {
                streak++;
            } else streak = 0;
            maxSubarrays = max(maxSubarrays, streak);
        }
        return maxSubarrays;
    }
};