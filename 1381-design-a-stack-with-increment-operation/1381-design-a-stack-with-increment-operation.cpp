class CustomStack {
public:
    int sz=0;
    int top=-1;
    vector<int>stack;
    CustomStack(int maxSize) 
    {
        sz=maxSize;
        stack.resize(sz,0);
    }
    
    void push(int x) 
    {
        if(top+1<sz)
            stack[++top]=x;
    }
    
    int pop() 
    {
        return top>=0?stack[top--]:-1;    
    }
    
    void increment(int k, int val) 
    {
    for(int i=0;i<=min(top,k-1);i++)
    {
        stack[i]+=val;
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