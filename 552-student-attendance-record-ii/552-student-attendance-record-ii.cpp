class Solution {
public:
    int mod=1e9+7;
    int dp[100001][3][2]={0};    
    int memo(int n,int l,int a)
    {
        if(n==0)
            return 1;
        if(dp[n][l][a]!=0)
            return dp[n][l][a];
        int ans=memo(n-1,0,a);
        if(!a)
            ans=(1LL*ans+memo(n-1,0,1))%mod;
        if(l<=1)
            ans=(1LL*ans+memo(n-1,l+1,a))%mod;
        return dp[n][l][a]=ans;
    }
    int checkRecord(int n) 
    {
        return memo(n,0,0);
    }
};