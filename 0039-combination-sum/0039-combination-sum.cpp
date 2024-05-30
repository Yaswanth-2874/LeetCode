class Solution {
    int target;
    vector<vector<int>> ans;
    
    void solve(vector<int>& candidates, vector<int>& currentCombination ,int left = 0, int currentSum = 0) {
        if(currentSum > target) return;
        if(currentSum == target) {
            ans.push_back(currentCombination);
            return;
        }

        for(int i = left; i < candidates.size(); i++) {
            currentCombination.push_back(candidates[i]);
            solve(candidates, currentCombination, i, currentSum+candidates[i]);
            currentCombination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        vector<int> currentCombination;
        solve(candidates, currentCombination);
        return ans;
    }
};