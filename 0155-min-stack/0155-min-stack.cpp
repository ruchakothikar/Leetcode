class MinStack {
public:
    stack<int> stack1;
    stack<int> minVal;
    MinStack() {
        
    }
    
    void push(int val) {
        stack1.push(val);
        if(minVal.empty() || val<=minVal.top())
        {
            minVal.push(val);
        }
    }
    
    void pop() {
        if(stack1.top()==minVal.top())
        {
            minVal.pop();
        }
        stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return minVal.top();
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