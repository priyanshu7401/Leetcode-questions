class Solution {
public:
    int distinctSubseqII(string s) 
    {
        int n=size(s);
        int mod=1e9+7;
        vector<int>dp(n+1,0);
        dp[n]=1;
        vector<int>alpha(26,-1);
        for(int i=n-1;i>=0;i--)
        {
            
            dp[i]=(1LL*dp[i+1]*2)%mod;
            if(alpha[s[i]-'a']!=-1)dp[i]-=dp[alpha[s[i]-'a']+1];
            dp[i]%=mod;
            alpha[s[i]-'a']=i;
        }
        return (dp[0]+mod-1)%mod;
    }
};