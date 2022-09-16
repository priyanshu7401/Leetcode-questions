typedef long long ll;
class Solution {
public:
    ll helper(vector<int>&n,vector<int>&m,int si,int i,vector<vector<int>>&dp)
    {
        if(i>=m.size())
            return 0;
        if(dp[i][si]!=INT_MIN)
            return dp[i][si];
        int ei=n.size()-1 -(i-si);
        ll ans1=1LL*m[i]*n[si]+helper(n,m,si+1,i+1,dp);
        ll ans2=1LL*m[i]*n[ei]+helper(n,m,si,i+1,dp);
        return dp[i][si]=max(ans1,ans2);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        vector<vector<int>>dp(multipliers.size(),vector<int>(multipliers.size(),INT_MIN));
        return helper(nums,multipliers,0,0,dp);
    }
};