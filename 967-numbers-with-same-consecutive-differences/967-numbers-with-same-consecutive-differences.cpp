class Solution {
public:
    vector<int>ans;
    void dfs(int s,int n,int k)
    {
        if(n==0)
        {
            ans.push_back(s);
            return;
        }
        if(s%10+k<=9)
            dfs(s*10+((s%10)+k),n-1,k);
        if(s%10-k>=0&&k!=0)
            dfs(s*10+((s%10)-k),n-1,k);        
    }
    vector<int> numsSameConsecDiff(int n, int k) 
    {
    for(int i=1;i<=9;i++)
    {
        dfs(i,n-1,k);
    }
        return ans;
    }
};