class Solution {
    int findLowerPosition(vector<int>& nums, int value) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] >= value)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right + 1;
    }
    int findHigherPosition(vector<int>& nums, int value) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] <= value)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
    
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        #define int long long
        sort(nums.begin(), nums.end());
        int validPairs = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            int minValue = lower - nums[i];
            int maxValue = upper - nums[i];
            int higherPos = findHigherPosition(nums, maxValue);
            int lowerPos = findLowerPosition(nums, minValue);
            
            if(lowerPos <= i+1)
                lowerPos = i+1;
            if(higherPos < i+1)
                continue;
            
            // cout<<"Lower index : "<<lowerPos<<endl;
            // cout<<"Higher index : "<<higherPos<<endl;
            
            int totalValues = higherPos - lowerPos + 1;
            validPairs += totalValues;
        }
        
        #undef int
        return validPairs;
    }
};