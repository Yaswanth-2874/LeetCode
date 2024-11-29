class Solution {
    // As i promised, here's the better version of my previous approach
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(!intervals.size())
            return {newInterval};
        
        int newIntervalStart = newInterval[0];
        int newIntervalEnd = newInterval[1];
        vector<vector<int>> newIntervals;
        int n = intervals.size();
        bool inserted = false;
        
        for(int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(newIntervalStart > end || start > newIntervalEnd) {
                if(!inserted && start > newIntervalEnd) {
                    inserted = true;
                    newIntervals.push_back({newIntervalStart, newIntervalEnd});
                }
                newIntervals.push_back({start, end});
                continue;
            }
            
            newIntervalStart = min(start, newIntervalStart);
            newIntervalEnd = max(end, newIntervalEnd);
            
            if(i + 1 >= n || newIntervalEnd < intervals[i+1][0]) {
                inserted = true;
                newIntervals.push_back({newIntervalStart, newIntervalEnd});
            }
        }
        if(!inserted)
            newIntervals.push_back({newIntervalStart, newIntervalEnd});
        
        return newIntervals;
    }
};