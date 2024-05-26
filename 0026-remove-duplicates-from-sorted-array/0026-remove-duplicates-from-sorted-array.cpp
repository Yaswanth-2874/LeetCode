class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int right = i;
            while(right < nums.size() && nums[i] == nums[right]) {
                right++;
            }
            nums[index++] = nums[i];
            i = right-1;
        }
        return index;
    }
};