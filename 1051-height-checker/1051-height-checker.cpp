class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        int count = 0;
        sort(sortedHeights.begin(), sortedHeights.end());
        for(int i = 0; i < heights.size(); i++) {
            count += heights[i] != sortedHeights[i];
        }
        return count;
    }
};