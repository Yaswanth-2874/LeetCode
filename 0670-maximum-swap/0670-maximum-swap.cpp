class Solution {
    string findMaxNumber(string& number, int index) {
        if(index >= number.size())
            return number;
        
        int maxPos = index;
        int maxNum = number[index] - '0';
        
        for(int i = index + 1; i < number.size(); i++) {
            if(maxNum <= number[i] - '0') {
                maxNum = number[i] - '0';
                maxPos = i;
            }
        }
        if(index == maxPos || maxNum == number[index] - '0')
            return findMaxNumber(number, index+1);
        
        swap(number[index], number[maxPos]);
        return number;
    }
public:
    int maximumSwap(int num) {
        string numberInString = to_string(num);
        
        return stoi(findMaxNumber(numberInString, 0));
    }
};