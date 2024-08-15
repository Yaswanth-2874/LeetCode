class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twenties = 0;
        for(int& num : bills) {
            if(num == 5)
                fives++;
            if(num == 10) {
                if(!fives)
                    return false;
                fives--;
                tens++;
            }
            if(num == 20) {
                if(tens) {
                    tens--;
                    if(fives)
                        fives--;
                    else
                        return false;
                }
                else {
                    if(fives >= 3)
                        fives -= 3;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};