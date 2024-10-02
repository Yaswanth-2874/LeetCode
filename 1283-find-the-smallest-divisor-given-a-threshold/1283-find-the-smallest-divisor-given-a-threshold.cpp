class Solution {
    #define all(arr) arr.begin(), arr.end()
    
    bool doesItSatisfyThreshold(vector<int>& nums, int threshold, int divisionValue) {
        for(int num : nums) {
            threshold -= (num + divisionValue - 1) / divisionValue;
            if(threshold < 0)
                return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int smallest = 1, largest = *max_element(all(nums));
        
        while(smallest <= largest) {
            int middle = smallest + (largest - smallest) / 2;
            if(doesItSatisfyThreshold(nums, threshold, middle))
                largest = middle - 1;
            else
                smallest = middle + 1;
        }
        return largest + 1;
    }
};