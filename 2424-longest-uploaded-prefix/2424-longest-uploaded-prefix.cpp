class LUPrefix {
    unordered_set<int>s;
    int i=0;
public:

    LUPrefix(int n) 
    {
    }
    void upload(int video) 
    {
        s.insert(video);
        while(s.find(i+1)!=s.end())i++;
    }
    
    int longest() 
    {
        return i;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */