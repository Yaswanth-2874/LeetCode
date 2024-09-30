class CustomStack {
    stack<int> st, temp;
    int maxSize;
    int currentSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        currentSize = 0;
    }
    
    void push(int x) {
        if(currentSize == maxSize)
            return;
        currentSize++;
        st.push(x);
    }
    
    int pop() {
        if(st.empty())
            return -1;
        int top = st.top();
        st.pop();
        currentSize--;
        return top;
    }
    
    void increment(int k, int val) {
        int size = st.size();
        int dontModify = max(size - k, 0);
        while(dontModify--) {
            temp.push(st.top());
            st.pop();
        }
        while(!st.empty()) {
            temp.push(st.top() + val);
            st.pop();
        }
        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */