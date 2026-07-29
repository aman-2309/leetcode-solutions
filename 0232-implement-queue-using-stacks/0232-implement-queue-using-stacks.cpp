class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    int tp;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st1.empty()) tp=x;
        st1.push(x);
    }
    
    int pop() {
        while(st1.size()>1){
            st2.push(st1.top());
            st1.pop();
        }
        int t = st1.top();
        st1.pop();
        while(not st2.empty()){
            if(st1.empty()) tp=st2.top();
            st1.push(st2.top());
            st2.pop();
        }
        return t;
    }
    
    int peek() {
        return tp;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */