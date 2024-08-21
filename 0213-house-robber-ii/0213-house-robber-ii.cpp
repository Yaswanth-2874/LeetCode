class Solution {
    vector<int> memo;
    int calcAmt(vector<int>& nums, int house, bool robbedFirst = false) {
        if(house == nums.size() - 1) {
            if(robbedFirst)
                return 0;
            return nums[house];
        }
        if(house >= nums.size())
            return 0;
        if(memo[house] != -1)
            return memo[house];
        
        int firstChoice = nums[house] + calcAmt(nums, house + 2, robbedFirst);
        int secondChoice = calcAmt(nums, house + 1, robbedFirst);
        
        return memo[house] = max(firstChoice, secondChoice);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        memo = vector<int> (nums.size(), -1);
        int ans1 = calcAmt(nums, 0, true);
        
        for(int& num : memo)
            num = -1;
        
        int ans2 = calcAmt(nums, 1, false);
        
        return max(ans1, ans2);
    }
};