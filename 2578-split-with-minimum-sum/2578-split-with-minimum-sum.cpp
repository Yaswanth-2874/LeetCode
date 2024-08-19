class Solution {
public:
    int splitNum(int num) {
        string givenNum = to_string(num);
        sort(givenNum.begin(), givenNum.end());
        
        string num1 = "", num2 = "";
        for(int i = 0; i < givenNum.size(); i++) {
            if(i % 2)
                num1.push_back(givenNum[i]);
            else
                num2.push_back(givenNum[i]);
        }
        
        return stoi(num1) + stoi(num2);
    }
};