class Solution {
    static bool comparator(string& a, string& b) {
        return a+b > b+a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numberInString;
        for(int num : nums)
            numberInString.push_back(to_string(num));
        
        sort(numberInString.begin(), numberInString.end(), comparator);
        if(numberInString[0] == "0")
            return "0";
        
        string largestNumber = "";
        for(auto& st : numberInString)
            largestNumber += st;
        
        return largestNumber;
    }
};