class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = -1;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(prev >= nums[i]) {
                ans += prev + 1 - nums[i];
                nums[i] = prev + 1;
            }
            prev = nums[i];
        }
        return ans;
    }
};


