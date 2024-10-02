class Solution {
    #define all(arr) arr.begin(), arr.end()
    int m, k;
    
    bool canGetRequiredBouquets(vector<int>& bloomDay, int currentDay) {
        int obtainedBouquets = 0;
        int currentBlooms = 0;
        for(int bloomed : bloomDay) {
            if(bloomed <= currentDay) {
                currentBlooms++;
            } else {
                currentBlooms = 0;
            }
            
            if(currentBlooms == k) {
                obtainedBouquets++;
                currentBlooms = 0;
            }
        }
        return obtainedBouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxBouquets = bloomDay.size() / k;
        if(maxBouquets < m)
            return -1;
        
        this->m = m;
        this->k = k;
        
        int minDay = 1, maxDay = *max_element(all(bloomDay));
        
        while(minDay <= maxDay) {
            int currentDay = minDay + (maxDay - minDay) / 2;
            if(canGetRequiredBouquets(bloomDay, currentDay))
                maxDay = currentDay - 1;
            else
                minDay = currentDay + 1;
        }
        return maxDay + 1;
    }
};