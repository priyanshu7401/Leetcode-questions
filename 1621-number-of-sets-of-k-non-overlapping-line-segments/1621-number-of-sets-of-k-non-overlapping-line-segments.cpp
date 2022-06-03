class Solution 
{
public:
    int mod=1e9+7;
    vector<vector<vector<int>>>memo; 
    int helper(int n,int k,bool start)
    {
        if(k==0)
            return 1;
        if(n==0)
            return 0;
        if(memo[n][k][start]!=-1)
            return memo[n][k][start];
        
        long long ans=helper(n-1,k,true);
        if(!start)
            ans=(ans+helper(n-1,k,false))%mod;            
        if(start)
            ans=(ans+helper(n,k-1,false))%mod;    
        
        return memo[n][k][start]=ans;        
    }
    int numberOfSets(int n, int k) 
    {
        memo.resize(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return helper(n,k,false);
    }
};