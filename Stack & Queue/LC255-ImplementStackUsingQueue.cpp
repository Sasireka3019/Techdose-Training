class MyStack {
public:
    queue <int> que;
    MyStack() {
        
    }
    
    void push(int x) {
        int n = que.size();
        que.push(x);
        for(int i=0; i<n; i++)
        {
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int top = que.front();
        que.pop();
        return top;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
