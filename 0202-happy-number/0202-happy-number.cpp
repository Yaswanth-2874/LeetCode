class Solution {
    int calcSquareOfDigits(int n) {
        int sum = 0;
        while(n) {
            int rem = n%10;
            sum += rem*rem;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = calcSquareOfDigits(n);
        int fast = calcSquareOfDigits(slow);
        cout<<slow<<" "<<fast<<endl;
        while(fast != slow) {
            if(fast == 1)
                return true;
            slow = calcSquareOfDigits(slow);
            fast = calcSquareOfDigits(calcSquareOfDigits(fast));
        }
        return fast == 1;
    }
};