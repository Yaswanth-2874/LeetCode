class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        for(int i = 0; i < nums.size();) {
            if(nums[i] > 0 && nums[i]-1 < nums.size() && nums[i] != nums[nums[i] - 1]) {
            //make sure to place nums[i] in index nums[i] - 1 as long as the index is valid
                swap(nums[i], nums[nums[i] - 1]);
            }
            else
                i++;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i+1)
                return i+1;
        }
        
        return nums.size() + 1;
    }
};