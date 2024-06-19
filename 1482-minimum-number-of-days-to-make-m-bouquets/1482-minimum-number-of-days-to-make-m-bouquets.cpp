class Solution {
    int totalBouquetsOnParticularDay(vector<int>& bloomDay, int currentDay, int k) {
        int totalBouquets = 0;
        int streak = 0;
        
        for(int bloom : bloomDay) {
            if(bloom > currentDay)
                streak = 0;
            else {
                if(streak == k - 1) {
                    streak = 0;
                    totalBouquets++;
                }
                else
                    streak++;
            }
        }
        return totalBouquets;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
        int left = 0, right = maxDay;
        
        while(left <= right) {
            int mid = left + (right - left)/ 2;
            if(totalBouquetsOnParticularDay(bloomDay, mid, k) >= m) {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        if(left > maxDay) return -1;
        return left;
    }
};