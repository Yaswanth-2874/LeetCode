class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for(auto st : logs) {
            if(st == "../")
                depth = max(depth-1, 0);
            else if (st != "./")
               depth++;
        }
        return depth;
    }
};