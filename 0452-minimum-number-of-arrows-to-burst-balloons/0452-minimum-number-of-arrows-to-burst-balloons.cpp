class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int arrowsRequired = 0;
        int n = points.size();
        
        for(int i = 0; i < n;) {
            int startTime = points[i][0];
            int endTime = points[i][1];
            int right = i+1;
            
            while(right < n && startTime <= endTime) {
                int commonStartTime = max(startTime, points[right][0]);
                int commonEndTime = min(endTime, points[right][1]);
                
                if(commonStartTime > commonEndTime) {
                    right--;
                    break;
                }
                
                startTime = commonStartTime;
                endTime = commonEndTime;
                right++;
            }
            
            arrowsRequired++;
            i = right + 1;
        }
        
        return arrowsRequired;
    }
};