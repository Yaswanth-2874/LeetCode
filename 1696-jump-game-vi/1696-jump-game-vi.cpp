class Solution {
    //HAD TO ACCESS HELP TO OPTIMISE THE MEMO
    //NEXT VISIT, I SHOULD SOLVE IT WITHOUT HELP
public:
    int maxResult(vector<int>& nums, int k) {
        int target = nums.size() - 1;
        vector<int> maxResult(nums.size(), INT_MIN);
        maxResult[target] = nums[target];
        
        priority_queue<pair<int, int>> pq;
        pq.push({nums[target], target});
        
        for(int index = target - 1; index >= 0; index--) {
            while(!pq.empty() && pq.top().second > index + k)
                pq.pop();
            
            maxResult[index] = nums[index] + pq.top().first;
            pq.push({maxResult[index], index});
        }
        return maxResult[0];
    }
};