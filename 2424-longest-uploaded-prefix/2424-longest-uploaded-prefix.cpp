class LUPrefix {
public:
    vector<int>vec;
    int i=0;
    LUPrefix(int n) 
    {
        vec.resize(200000,0);  
        i=1;
    }
    void upload(int video) 
    {
        vec[video]=1;
        while(vec[i])i++;
    }
    
    int longest() 
    {
        return i-1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */