class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int x) {
        if(st.empty())
        {
            st.push(make_pair(x,x));
        }
        else
        {
            int min_val=st.top().second;//-2
            if(x < min_val)
                min_val=x;
            st.push(make_pair(x,min_val));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};