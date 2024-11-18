class Solution {
    vector<int> decryptNegative(vector<int>& code, int k) {
        int sum = 0;
        int n = code.size();
        int left = 0, right = n-1;
        for(int i = 0; i < k; i++) {
            sum += code[right--];
        }
        vector<int> decryptedCode;
        right++;
        
        int iterations = n;
        while(iterations--) {
            right %= n;
            left %= n;
            
            decryptedCode.push_back(sum);
            sum -= code[right++];
            sum += code[left++];
        }
        return decryptedCode;
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sum = 0;
        int n = code.size();
        
        if(k < 0) {
           return decryptNegative(code, -k);
        }
        
        for(int i = 1; i < k+1; i++) {
            sum += code[i%n];
        }
        
        int left = 1, right = k+1;
        int iterations = code.size();
        vector<int> decryptedCode;
        
        while(iterations--) {
            right %= n;
            left %= n;
            
            decryptedCode.push_back(sum);
            sum += code[right++];
            sum -= code[left++];
        }
    
        return decryptedCode;
    }
};