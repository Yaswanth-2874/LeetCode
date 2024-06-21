class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int totalCustomers = 0, unsatisfiedCustomer = 0;
        int left = 0, right = 0, maxSum = 0, currentSum = 0;
        
        while(right < minutes) {
            totalCustomers += customers[right];
            unsatisfiedCustomer += grumpy[right]*customers[right];
            currentSum += grumpy[right]*customers[right++];
        }
        for(right = minutes; right < grumpy.size(); right++) {
            maxSum = max(currentSum, maxSum);
            unsatisfiedCustomer += grumpy[right]*customers[right];
            currentSum += grumpy[right]*customers[right];
            currentSum -= grumpy[left]*customers[left++];
            totalCustomers += customers[right];
        }
    
        maxSum = max(currentSum , maxSum);
        return totalCustomers - unsatisfiedCustomer + maxSum;
    }
};