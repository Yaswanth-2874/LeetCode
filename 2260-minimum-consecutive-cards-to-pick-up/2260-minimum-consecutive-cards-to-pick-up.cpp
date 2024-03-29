class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> freq;
        int left = 0, ans = -1;
        bool flag = false;
        
        for(int right = 0; right < cards.size(); right++) {
            freq[cards[right]]++;
            while(freq[cards[right]] == 2) {
                freq[cards[left++]]--;
                flag = true;
            }
            if(flag) {
                if(ans == -1) 
                    ans = right-left+2;
                else 
                    ans = min(ans, right-left+2);
                flag = 0;            
            }
        }
        return ans;
    }
};