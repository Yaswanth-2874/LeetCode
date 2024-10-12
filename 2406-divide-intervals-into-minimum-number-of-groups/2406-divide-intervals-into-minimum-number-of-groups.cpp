class Solution {
    // FIND MAX NUMBER OF INTERVALS AT A FIXED TIME
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        for(auto& interval : intervals) {
            events.push_back({interval[0], 1});
            events.push_back({interval[1] + 1, -1});
        }
        sort(events.begin(), events.end());
        // AFTER SORTING, THE -1 EVENT WILL DEFINITELY OCCUR FIRST IN THE SAME TIME PERIOD
        // FIRST ADD UP ALL THE -1 EVENTS BEFORE CONSIDERING FOR THE MAX
        
        int maxMergedIntervals = 0, currentIntervals = 0;
        
        for(auto& [time, status] : events) {
            if(status == -1) {
                currentIntervals--;
                continue;
            }
            if(status == 1) {
                currentIntervals++;
                maxMergedIntervals = max(currentIntervals, maxMergedIntervals);
            }
        }
        
        return maxMergedIntervals;
        
    }
};