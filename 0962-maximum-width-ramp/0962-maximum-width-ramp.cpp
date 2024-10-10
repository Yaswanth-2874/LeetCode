class Solution {
    // I FEEL STUPID FOR SOLVING IT WITH BINARY SEARCH INSTEAD OF SLIDING WINDOW
    // DAMN, SLIDING WINDOW IS SO MUCH EASIER!! WHY DIDNT I THINK ABOUT THIS
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> maxVisited = nums;
        int maxNum = nums.back();
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            maxNum = max(maxNum, nums[i]);
            maxVisited[i] = maxNum;
        }
        
        int maxWidth = 0;
        int left = 0;
        
        for(int right = 0; right < nums.size(); right++) {
            while(nums[left] > maxVisited[right]) {
                left++;
            } 
            int currentWindowSize = right - left;
            maxWidth = max(maxWidth, currentWindowSize);
        }
        return maxWidth;
    }
};