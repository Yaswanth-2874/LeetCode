class Solution {
    // CONSTRAINTS ARE LESS, EVEN BRUTE FORCE SIMULATION WILL GET ACCEPTED
    // WILL OPTIMISE AFTER BRUTE FORCING
    string reverseInvert(string s) {
        reverse(s.begin(), s.end());
        string& reversed = s;
        for(auto& ch : reversed) {
            ch = ch == '1' ? '0' : '1';
        }
        return reversed;
    }
public:
    char findKthBit(int n, int k) {
        string si = "0";
        for(int i = 1; i < n; i++) {
            string newString = si;
            newString.push_back('1');
            newString += reverseInvert(si);
            si = newString;
        }
        // cout<<si<<endl;
        return si[k-1];
    }
};