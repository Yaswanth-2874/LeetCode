class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        vector<int> ans;
        
        for(int num : nums) {
            rightSum -= num;
            ans.push_back(abs(rightSum - leftSum));
            leftSum += num;
        }
        
        return ans;
    }
};

