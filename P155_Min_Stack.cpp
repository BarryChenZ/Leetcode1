class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return *min_element(stack.begin(), stack.end());
    }
};
