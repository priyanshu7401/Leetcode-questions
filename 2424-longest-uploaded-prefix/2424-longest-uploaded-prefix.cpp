class LUPrefix {
    int vec[100001]={0};
    int i=1;
public:

    LUPrefix(int n) 
    {
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