class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        long long num = nums.front();
        long long pre = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > num) {
                ans += (i - pre)*num;
                num = nums[i];
                pre = i;
            }
        }

        ans += (nums.size() - 1 - pre)*num;
        return ans;
    }
};