class FreqStack {
public:
    unordered_map<int,stack<int>>DSA;
    unordered_map<int,int>counter;
    int maxfreq=0;
    FreqStack() 
    {
        
    }
    
    void push(int val) 
    {
    DSA[++counter[val]].push(val);   
    maxfreq=max(maxfreq,counter[val]);
    
    }
    
    int pop() 
    {
        int ele=DSA[maxfreq].top(); 
        counter[ele]--;
        DSA[maxfreq].pop();
        if(DSA[maxfreq].empty())maxfreq--;
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */