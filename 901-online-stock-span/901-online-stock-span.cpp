class StockSpanner {
public:
    stack<int>s;
    vector<int>vec;
    StockSpanner() 
    {
        s.push(-1);
    }
    
    int next(int price) 
    {
    
    while(s.top()!=-1&&vec[s.top()]<=price)s.pop();
    int ans=vec.size()-s.top(); 
    s.push(vec.size());
    vec.push_back(price);
    return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */