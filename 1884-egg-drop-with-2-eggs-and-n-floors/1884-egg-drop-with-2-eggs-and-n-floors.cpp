class Solution {
public:
    int twoEggDrop(int n, int num = 1) {
        if(n <= 0)
            return 0;
        return 1 + twoEggDrop(n - num, num + 1);
    }
};