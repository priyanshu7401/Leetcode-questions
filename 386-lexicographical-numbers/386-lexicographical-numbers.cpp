class Solution {
public:
    
    vector<int> lexicalOrder(int n) 
    {
    auto cmp=[&](int a,int b)
    {
        string x=to_string(a);
        string y=to_string(b);
        
        return x<y;
    };
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)ans[i]=1+i;
        sort(begin(ans),end(ans),cmp);
        return ans;
    }
};