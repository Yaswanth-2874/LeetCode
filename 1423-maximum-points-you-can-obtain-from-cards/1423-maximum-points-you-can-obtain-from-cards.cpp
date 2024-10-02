class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalCards = cardPoints.size();
        int ignoreCards = totalCards - k;
        int currentTotal = 0;
        
        for(int i = 0; i < ignoreCards; i++) {
            currentTotal += cardPoints[i];
        }
        int minTotal = currentTotal;
        int left = 0, right = ignoreCards;
        
        while(right < totalCards) {
            currentTotal -= cardPoints[left++];
            currentTotal += cardPoints[right++];
            minTotal = min(minTotal, currentTotal);
        }
        int totalPoints = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        return totalPoints - minTotal;
    }
};