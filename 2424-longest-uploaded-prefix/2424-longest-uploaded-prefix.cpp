class LUPrefix {
    unordered_set<int>s;
    int last=0;
public:

    LUPrefix(int n) 
    {
    }
    void upload(int video) 
    {
        s.insert(video);
        while(s.count(last+1))last++;
    }
    
    int longest() 
    {
        return last;
    }
};