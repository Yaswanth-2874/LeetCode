class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto detail : details) {
            count += ((detail[11] >= '6' && detail[12] >= '1') || detail[11] >= '7');
        }
        return count;
    }
};