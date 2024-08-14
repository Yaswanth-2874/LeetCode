class Solution {
    int findMinJumps(vector<int>& nums, vector<int>& memo, int index = 0) {
        int minSteps = INT_MAX;
        if(nums.size() - 1 <= index) {
            return 0;
        }
        
        if(memo[index] != -1)
            return memo[index];
        
        int maxSteps = nums[index];
        for(int i = maxSteps; i >= 1; i--) {
            int steps = findMinJumps(nums, memo, index + i);
            if(steps != -1)
                minSteps = min(1 + steps, minSteps);
        }
        return memo[index] = (minSteps == INT_MAX ? -1 : minSteps);
    }
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return findMinJumps(nums, memo);
    }
};