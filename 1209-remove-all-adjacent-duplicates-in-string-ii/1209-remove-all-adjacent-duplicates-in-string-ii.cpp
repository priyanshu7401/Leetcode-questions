class Solution {
public:
    string removeDuplicates(string a, int k) 
    {
    stack<pair<char,int>>s;
    int temp=1;
    int n=size(a);
    for(int i=0;i<n;i++)
    {
        if(!s.empty()&&s.top().first==a[i])temp=s.top().second+1;
        else temp=1;
        s.push({a[i],temp});
       
        if(temp==k)
        {
            while(!s.empty()&&s.top().second>=1&&s.top().first==a[i])
            {
                s.pop();
                temp++;
            }
        }
    }
        string ans="";
        while(!s.empty())
        {
            ans+=s.top().first;
            s.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};