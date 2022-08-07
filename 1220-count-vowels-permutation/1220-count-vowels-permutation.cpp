class Solution {
public:
    int countVowelPermutation(int n)
    {
    vector<long>dp(5,1),ap(5);
    int mod=1e9+7;
    for(int i=1;i<n;i++)
    {
        ap=dp;
        dp[0]=ap[1]%mod;
        dp[1]=(ap[0]+ap[2])%mod;
        dp[2]=(ap[0]+ap[1]+ap[3]+ap[4])%mod;
        dp[3]=(ap[2]+ap[4])%mod;
        dp[4]=ap[0]%mod;
    }
        int ans=0;
        for(int i=0;i<5;i++)
        {
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};