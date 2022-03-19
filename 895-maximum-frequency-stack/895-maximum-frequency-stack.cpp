class FreqStack {
public:
    map<int,stack<int>>DSA;
    map<int,int>counter;
    stack<int>s;
    FreqStack() 
    {
        
    }
    
    void push(int val) 
    {
    DSA[++counter[val]].push(val);   
    if(DSA[counter[val]].size()==1)
        s.push(counter[val]);
    }
    
    int pop() 
    {
        int ele=DSA[s.top()].top(); 
        counter[ele]--;
        DSA[s.top()].pop();
        if(DSA[s.top()].empty())s.pop();
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */