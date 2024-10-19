class Solution {
    // Size of nthString is always 2^n - 1
    // If i generate nthString time complexity always goes up exponentitally
    // Inorder to optimise, i should not generate the nthString
    
    // How else could i find out the kth string?
    
    // EveryString is comprised of (previousString) + 1 + (inverted, reversed, previousString)
    // Can i use divide and conquer?
    
    // 011 1 001
    // 0 1 1    
    char kthBit(int n, int k) {
        if(n == 1)
            return '0';
        
        int length = (1 << n) - 1;
        int mid = length/2;
        // cout<<mid<<endl;
        
        if(k == mid)
            return '1';
        
        if(k < mid)
            return kthBit(n-1, k);
            
        int kthIndex = mid - (k - mid);
        // cout<<kthIndex<<endl;

        return kthBit(n-1, kthIndex) == '1' ? '0' : '1';
    }
    
public:
    char findKthBit(int n, int k) {
        return kthBit(n, k-1);
    }
};