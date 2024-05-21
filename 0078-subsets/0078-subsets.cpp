class Solution {
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, vector<int>& current, int left = 0) {
        ans.push_back(current);
        if(left >= nums.size()) return;
        for(int i = left; i < nums.size(); i++) {
            current.push_back(nums[i]);
            solve(nums, current, i+1);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> set;
        solve(nums, set);
        return ans;
    }
};