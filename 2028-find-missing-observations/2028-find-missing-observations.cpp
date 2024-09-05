class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int knownOutcomes = rolls.size();
        int targetSum = mean * (knownOutcomes + n);
        targetSum -= accumulate(rolls.begin(), rolls.end(), 0);
        
        if(targetSum > 6 * n || targetSum < n)
            return {};
        
        int value = targetSum/ n;
        targetSum %= n;
        vector<int> missingObservations(n, value);
        
        while(targetSum) {
            missingObservations[targetSum--]++;
        }
    
        return missingObservations;
        
    }
};


// target = 8
// n = 3 => [3 , 3]
