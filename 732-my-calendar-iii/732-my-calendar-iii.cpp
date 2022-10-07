class MyCalendarThree {
public:
    map<int,int>mp;
    int ans=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) 
    {
        mp[start]++;
        mp[end]--;
        int count=0;
        for(auto [i,j]:mp)
        {
            count+=j;
            ans=max(ans,count);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */