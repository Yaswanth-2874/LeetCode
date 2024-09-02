class Solution {
    unordered_set<long> stones;
    unordered_map<long, unordered_map<long, bool>> memo;
    int target;
    
    bool canReachEnd(long currentPos, long jumpSize) {
        if(currentPos == target)
            return true;
        if(stones.find(currentPos) == stones.end())
            return false;
        if(memo[currentPos].find(jumpSize) != memo[currentPos].end())
            return memo[currentPos][jumpSize];
        
        bool canCross = false;
        if(jumpSize > 0) {
            canCross = canReachEnd(currentPos + jumpSize, jumpSize) ||
                       canReachEnd(currentPos + jumpSize + 1, jumpSize + 1) ||
                       canReachEnd(currentPos + jumpSize - 1, jumpSize - 1);
        }
        
        return memo[currentPos][jumpSize] = canCross;
    }

public:
    bool canCross(vector<int>& stonesL) {
        if(stonesL[1] - stonesL[0] > 1)
            return false;
        target = stonesL.back();
        
        for(int stone : stonesL)
            stones.insert(stone);
        
        return canReachEnd(1, 1);
    }
};
