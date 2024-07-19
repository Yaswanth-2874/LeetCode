class MinStack {
public:
    vector<int> stack;
    vector<int> minElements;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if(!minElements.size() || getMin() >= val)
            minElements.push_back(val);
    }
    
    void pop() {
        int topElement = top();
        stack.pop_back();
        if(topElement == getMin())
            minElements.pop_back();
        
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return minElements[minElements.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */