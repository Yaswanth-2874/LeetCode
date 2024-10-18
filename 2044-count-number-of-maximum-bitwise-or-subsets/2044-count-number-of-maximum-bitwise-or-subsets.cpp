class Solution {
    // MAX BITWISE OR IS DEFINITELY RESULT OF BITWISE OR ON EVERY ELEMENT
    // SINCE CONSTRAINTS ARE QUITE SMALL DO PICK NOT PICK (no need of dp also)
    int findNumberOfWays(vector<int>& nums, int targetOR, int index, int currentOR) {
        if(index == nums.size())
            return currentOR == targetOR;
                
        int pick = findNumberOfWays(nums, targetOR, index+1, currentOR | nums[index]);
        int dontPick = findNumberOfWays(nums, targetOR, index+1, currentOR);
        
        return pick + dontPick;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxORValue = 0;
        for(int& num : nums) {
            maxORValue |= num;
        }
        return findNumberOfWays(nums, maxORValue, 0, 0);
    }
};