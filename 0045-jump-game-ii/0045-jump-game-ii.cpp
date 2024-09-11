class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> minJumps(nums.size(), INT_MAX);
        int targetPlace = nums.size() - 1;
        
        minJumps[targetPlace] = 0;
        
        for(int index = targetPlace - 1; index >= 0; index--) {
            int maxJump = nums[index];
            while(maxJump >= 1) {
                int destination = index + maxJump;
                // cout<<destination<<" "<<maxJump<<endl;
                if(destination >= targetPlace) {
                    minJumps[index] = 1;
                    break;
                } else if(minJumps[destination] != INT_MAX) {
                    minJumps[index] = min(1 + minJumps[destination], minJumps[index]);
                }
                maxJump--;
            }
        }
        
        return minJumps[0];
    }
};