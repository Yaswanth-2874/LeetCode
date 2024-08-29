class Solution {

    int findTotalWays(vector<int>& nums, int target, int sum = 0, int index = 0) {
        if(index >= nums.size())
            return sum == target;
        
        int addCurr = findTotalWays(nums, target, sum+nums[index], index+1);
        int subCurr = findTotalWays(nums, target, sum-nums[index], index+1);
        
        return addCurr + subCurr;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return findTotalWays(nums, target);
    }
};