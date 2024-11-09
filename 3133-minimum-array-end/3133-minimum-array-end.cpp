class Solution {
    string toBinary(int n) {
        string binary = "";
        
        for(int bitPos = 0; bitPos < 32; bitPos++) {
            int bit = 1 << bitPos;
            if(bit & n)
                binary.push_back('1');
            else
                binary.push_back('0');
        }
        
        //My binary form is reversed of actual binary
        return binary;
    }
public:
    long long minEnd(int n, int x) {
        long long minValue = x;
        string binaryForm = toBinary(n-1);
        int left = 0;
        
        for(int bitPos = 0; bitPos < 64; bitPos++) {
           if(left == 32)
               break;
            long long bit = 1LL << bitPos;
            
            if((bit & minValue) == 0) {
                int value = binaryForm[left++] - '0';
                if(value)
                    minValue |= bit;
            }
        }
        
        return minValue;
    }
};

// Touch only the unset bits of x
// the binary pattern of n should be applied on unset bits
// x = 100
// n = 11 => n-1 = 10
// the pattern of n-1 should be inserted in x (n-1 because 1 digit is already considered)
// 110 should be the answer