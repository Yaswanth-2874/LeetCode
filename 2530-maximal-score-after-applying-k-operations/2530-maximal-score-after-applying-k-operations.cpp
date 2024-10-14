class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int& num : nums) {
            pq.push(num);
        }
        
        long long maxScore = 0;
        
        while(k--) {
            int bestElement = pq.top();
            pq.pop();
            maxScore += bestElement;
            pq.push((bestElement + 2)/3);
        }
        
        return maxScore;
    }
};