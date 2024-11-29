class Solution {
    // On my way to optimise this shitty code
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(!intervals.size())
            return {newInterval};
        
        int newIntervalStart = newInterval[0];
        int newIntervalEnd = newInterval[1];
        
        intervals.push_back({newIntervalStart, newIntervalEnd});
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> newIntervals;
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        int n = intervals.size();
        
        for(int i = 0; i < n; i++) {
            int commonStart = max(start, intervals[i][0]);
            int commonEnd = min(end, intervals[i][1]);
            
            if(commonStart > commonEnd) {
                newIntervals.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = max(end, intervals[i][1]);
            }
        }
        
        newIntervals.push_back({start, end});
        return newIntervals;
    }
};