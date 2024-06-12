class Solution {
public:
    void sortColors(vector<int>& nums) {
        int first = 0, last = nums.size()-1;
        
        for(int mid = 0; mid <= last; mid++) {
            if(nums[mid] == 0)
                swap(nums[first++],nums[mid]);
            else if(nums[mid] == 2)
                swap(nums[last--],nums[mid--]);
        }
    }
};