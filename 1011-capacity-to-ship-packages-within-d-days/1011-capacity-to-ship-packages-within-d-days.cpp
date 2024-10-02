class Solution {
    #define all(arr) arr.begin(), arr.end()
    
    bool canShipWithGivenWeight(vector<int>& weights, int maxWeight, int targetDays) {
        int currentWeight = 0;
        int totalDays = 1;
        for(int weight : weights) {
            if(weight > maxWeight)
                return false;
            if(currentWeight + weight > maxWeight) {
                totalDays++;
                currentWeight = 0;
            }
            currentWeight += weight;
        }
        // cout<<totalDays<<" for weight "<<maxWeight<<endl;
        return totalDays <= targetDays;
    }    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minWeight = 1, maxWeight = accumulate(all(weights), 0);
        while(minWeight <= maxWeight) {
            int currentWeight = minWeight + (maxWeight - minWeight) / 2;
            if(canShipWithGivenWeight(weights, currentWeight, days)) {
                maxWeight = currentWeight - 1;
            } else  {
                minWeight = currentWeight + 1;
            }
        }
        return maxWeight + 1;
    }
};