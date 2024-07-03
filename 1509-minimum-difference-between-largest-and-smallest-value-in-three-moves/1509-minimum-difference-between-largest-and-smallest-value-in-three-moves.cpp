class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() < 4) return 0;
        
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 4;
        int minDiff = INT_MAX;
        
        while(right < nums.size()) {
            minDiff = min(minDiff, nums[right++] - nums[left++]);
        }
        return minDiff;
    }
};


