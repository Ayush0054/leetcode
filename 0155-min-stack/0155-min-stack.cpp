class MinStack {
public:
    // MinStack() {
        stack<int> s;
        int minl = INT_MAX;
    // }
    
    void push(int val) {
        if(minl>=val){
            s.push(minl);
            minl=val;
        }
        s.push(val);
    }
    
    void pop() {
        if(minl==s.top()){
            s.pop();
            minl=s.top();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minl;
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

     //1st approach
     // normal push
      // get min element and push it tosecond stack
      // in pop -> empty both stack
     // get min-> return second stack min element