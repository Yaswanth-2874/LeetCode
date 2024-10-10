class Solution {
    // 8 8 8 5 5 5
    // I FEEL LIKE THERE WOULD BE BETTER APPROACH THAN THIS BINARY SEARCH
    // PROBABLY WITH MONOTONIC STACK BUT NOT ABLE TO THINK TwT
    // WILL GRIND MORE
    
    int findMaxLength(int leftIndex, vector<int>& maxVisited, vector<int>& nums) {
        int left = leftIndex, right = maxVisited.size() - 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(maxVisited[mid] >= nums[leftIndex])
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return right - leftIndex;
    }
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> maxVisited = nums;
        int maxNum = nums.back();
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            maxNum = max(maxNum, nums[i]);
            maxVisited[i] = maxNum;
        }
        
        int maxWidth = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxWidth = max(maxWidth, findMaxLength(i, maxVisited, nums));
        }
        return maxWidth;
    }
};