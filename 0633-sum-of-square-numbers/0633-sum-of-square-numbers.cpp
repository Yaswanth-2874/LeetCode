class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i <= sqrt(c); i++) {
            double root = sqrt(c-i*i);
            if(root == (int)root)
                return true;
        }
        return false;
    }
};