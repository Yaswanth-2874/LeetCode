class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double averageTime = 0;
        long currentTime = 0, waitingTime = 0;
        
        for(auto& customer : customers) {
            if(currentTime < customer[0])
                currentTime  = customer[0];
            currentTime += customer[1];
            waitingTime += currentTime - customer[0];
        }
        return (double)waitingTime/customers.size();
    }
};