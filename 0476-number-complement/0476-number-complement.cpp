class Solution {
public:
    int findComplement(int num) {
        int totalBits = (log(num)/log(2)) + 1;
        int bit = 1, ans = 0;
        
        for(int i = 0; i < totalBits; i++) {
            if((bit & num) == false)
                ans += bit;
            bit <<= 1;
        }
        return ans;
    }
};

// 1 0 1 

