class Solution {
    #define all(n) n.begin(), n.end()
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArray = arr;
        sort(all(sortedArray));
        
        unordered_map<int, int> ranks;
        int currentRank = 1;
        
        for(int num : sortedArray) {
            if(ranks.find(num) == ranks.end()) {
                ranks[num] = currentRank;
                currentRank++;
            }
        }
        for(int& num : arr) {
            num = ranks[num];
        }
        return arr;
    }
};