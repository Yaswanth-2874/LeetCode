class Solution {
    int binarySearch(vector<pair<int, int>>& jobProfile, int skill) {
        int left = 0, right = jobProfile.size()-1;
        int currentProfit = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(jobProfile[mid].first <= skill) {
                currentProfit = max(currentProfit, jobProfile[mid].second);
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        // cout<<skill<<" : "<<currentProfit<<endl;
        return currentProfit;
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobProfile;
        for(int i = 0; i < profit.size(); i++) {
            jobProfile.push_back({ difficulty[i], profit[i]});
        }
        sort(jobProfile.begin(), jobProfile.end());
        
        int currentMax = 0;
        for(int i = 0; i < jobProfile.size(); i++) {
            jobProfile[i].second = max(jobProfile[i].second, currentMax);
            currentMax = max(jobProfile[i].second, currentMax);
            // cout<<jobProfile[i].second<<" ";
        }
        
        int maxProfit = 0;
        for(int num : worker) {
            maxProfit += binarySearch(jobProfile, num);
        }
        return maxProfit;
    }
};
