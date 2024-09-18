class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(!nums.size() || left >= nums.size() || nums[left] != target)
            return {-1, -1};
        int lowerBound = left;
        
        left = 0; right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return {lowerBound, left - 1};
    }
};