class Solution {
    string generateString(int n) {
        if(n == 1)
            return "0";
        string si = generateString(n-1);
        si.push_back('1');
        for(int i = si.size() - 2; i >= 0; i--) {
            char inverted = si[i] == '0' ? '1' : '0';
            si.push_back(inverted);
        }
        return si;
    }
public:
    char findKthBit(int n, int k) {
        string nthString = generateString(n);
        // cout<<nthString<<endl;
        return nthString[k-1];
    }
};