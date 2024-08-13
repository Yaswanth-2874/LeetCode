class Solution {
    vector<vector<int>> combSum;
    void findCombSum(vector<int>& nums, vector<int>& currentComb, int target, int index = 0) {
        if(target < 0)
            return;
        
        if(!target) {
                combSum.push_back(currentComb);
        }
        
        for(int i = index; i < nums.size(); i++) {
            if(i == index || nums[i] != nums[i-1]) {
                currentComb.push_back(nums[i]);
                findCombSum(nums, currentComb, target - nums[i], i+1);
                currentComb.pop_back();
            }
        }
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> currentComb;
        findCombSum(candidates, currentComb, target);
        return combSum;
    }
};