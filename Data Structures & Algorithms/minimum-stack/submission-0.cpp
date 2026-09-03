class MinStack {
public:
    stack<pair<int,int>> stk;
    MinStack() {
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val, val});
            return;
        }

        int min = stk.top().second;
        if(min > val){
            min = val;
        }
        stk.push({val, min});
    }
    
    void pop() {
        if(stk.empty())
            return;

        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
