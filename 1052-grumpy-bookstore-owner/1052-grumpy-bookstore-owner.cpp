class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int totalCustomers = 0, unsatisfiedCustomer = 0;
        vector<int> unsatisfiedCustomers;
        for(int i = 0; i < grumpy.size(); i++) {
            unsatisfiedCustomers.push_back(grumpy[i]*customers[i]);
            totalCustomers += customers[i];
            unsatisfiedCustomer += unsatisfiedCustomers[i];
        }
        
        int left = 0, right = 0, maxSum = 0, currentSum = 0;
        while(right < minutes) {
            currentSum += unsatisfiedCustomers[right++];
        }
        
        for(right = minutes; right < grumpy.size(); right++) {
            maxSum = max(currentSum, maxSum);
            currentSum += unsatisfiedCustomers[right];
            currentSum -= unsatisfiedCustomers[left++];
        }
        
        maxSum = max(currentSum , maxSum);
        return totalCustomers - unsatisfiedCustomer + maxSum;
    }
};