class Solution 
{
public:
    int mod=1e9+7;
    vector<vector<vector<int>>>memo; 
    int helper(int n,int k,bool start)
    {
        if(k==0)
            return 1;
        if(n==0||k>n)
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
        memo.resize(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        for(int i=0;i<=n;i++)
            memo[i][0][0]=1,memo[i][0][1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                
                  memo[i][j][1]=(1LL*(memo[i-1][j][1]+memo[i][j-1][0]))%mod;
                  memo[i][j][0]=(1LL*(memo[i-1][j][1]+memo[i-1][j][0]))%mod;                    
                
            }
        }
        return memo[n][k][0];
    }
};