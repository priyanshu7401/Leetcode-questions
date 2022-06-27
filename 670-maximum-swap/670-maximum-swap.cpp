class Solution {
public:
    int maximumSwap(int num) 
    {
        
        string s=to_string(num);
        
        int n=size(s);
        vector<int>store(10,0);
        
        for(int i=0;i<n;i++)
        {
            store[s[i]-'0']=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=9;j>=s[i]+1-'0';j--)
            {
                if(store[j]>i)
                {
                    swap(s[store[j]],s[i]);
                    // cout<<j<<" "<<s<<endl;
                    i=n;
                    break;
                }
            }
        }
        
        return stoi(s);
    }

};