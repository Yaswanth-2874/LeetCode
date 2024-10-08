class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(auto& bracket : s) {
            if(bracket == ']')
                if(st.size() && st.top() == '[') {
                    st.pop();
                    continue;
                }
            st.push(bracket);
        }
        
        int invalidBrackets = st.size() / 2;
        
        return (invalidBrackets + 1) / 2;
    }
};