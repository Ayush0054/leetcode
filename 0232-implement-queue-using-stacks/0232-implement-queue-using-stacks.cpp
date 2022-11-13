class MyQueue {
public:
       stack<int> s1;
        stack<int> s2;
        int curr;
    // MyQueue() {
    // }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            curr = s2.top();
            s2.pop();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            curr= s2.top();
            s2.pop();
        }
        return curr;
    }
    
    int peek() {
         if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
          return   s2.top();
        }
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        else return false;
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