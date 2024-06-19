class Solution {
    long calculateHours(vector<int>& piles, int eatingSpeed) {
        long eatingHours = 0;
        for(auto& pile : piles) {
            eatingHours += ceil((double)pile/eatingSpeed);
        }
        return eatingHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas = *max_element(piles.begin(), piles.end());
        int minBananas = 1;
        
        while(minBananas <= maxBananas) {
            int eatingSpeed = minBananas + (maxBananas - minBananas)/2;
            long eatingHours = calculateHours(piles, eatingSpeed);
            if(eatingHours > h) {
                minBananas = eatingSpeed + 1;
            }
            else
                maxBananas = eatingSpeed - 1;
        }
        
        return minBananas;
    }
};