class Solution {
    vector<int> memo;
    int k, target;
    
    bool partition(vector<int>& nums, int sum, int mask, int targetReached) {
        if(sum > target)
            return memo[mask] = false;
        
        if(targetReached == k)
            return memo[mask] = true;
        
        if(memo[mask] != -1)
            return memo[mask];
        
        if(sum == target)
            return memo[mask] = partition(nums, 0, mask, targetReached + 1);
      
        for(int i = 0; i < nums.size(); i++) {
            if(!(mask & (1<<i))) {
                if(partition(nums, sum + nums[i], mask | (1 << i), targetReached))
                    return memo[mask] = true;
            }
        }
        return memo[mask] = false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->k = k;
        int n = nums.size();
        memo = vector<int> (1 << n, -1);
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % k != 0)
            return false;
        
        sort(nums.begin(), nums.end(), greater<int> ());
        target = totalSum / k;
        if (nums[0] > target)
            return false;
        
        return partition(nums, 0, 0, 0);
    }
};