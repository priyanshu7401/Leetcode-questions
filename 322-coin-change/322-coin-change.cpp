class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<int>&coins,int i,int amount)
    {
        if(amount==0)
            return 0;
        if(i==size(coins)||amount<0)
            return 100000;           
        if(memo[i][amount]!=0)
            return memo[i][amount];
        int ans=dp(coins,i+1,amount);
        ans=min(ans,1+dp(coins,i,amount-coins[i]));
        return memo[i][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) 
    {
    int n=size(coins);
    memo.resize(n,vector<int>(amount+1,0));
    int ans=dp(coins,0,amount);
    return ans>10000?-1:ans;
    }
};