class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSubarraySum = 0;
        unordered_set<int> windowNums;
        unordered_map<int, int> repetitions;
        long long currentSubarraySum = 0;
        int n = nums.size();
        
        for(int i = 0; i < k-1; i++) {
            if(windowNums.count(nums[i])) {
                repetitions[nums[i]]++;
            }
            windowNums.insert(nums[i]);
            currentSubarraySum += nums[i];
        }
        
        int left = 0;
        int right = k-1;
        
        // cout<<currentSubarraySum<<endl;
        
        while(right < n) {
            if(windowNums.count(nums[right])) {
                repetitions[nums[right]]++;
            }
            windowNums.insert(nums[right]);
            currentSubarraySum += nums[right];
            
            if(repetitions.empty()) {
                maxSubarraySum = max(maxSubarraySum, currentSubarraySum);
            }
            // cout<<"Sum from "<<left<<" to "<<right<<" is : "<<currentSubarraySum<<endl;
            currentSubarraySum -= nums[left];
            right++;   
            
            if(repetitions.count(nums[left])) {
                repetitions[nums[left]]--;
                if(repetitions[nums[left]] == 0) 
                    repetitions.erase(nums[left]);
            } else {
                windowNums.erase(nums[left]);
            }
            left++;
        }
        
        return maxSubarraySum;
    }
};