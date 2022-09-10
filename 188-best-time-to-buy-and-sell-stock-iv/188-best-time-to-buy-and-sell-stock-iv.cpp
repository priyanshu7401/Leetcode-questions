class Solution {
public:
    vector<vector<vector<int>>>memo;
    int dp(vector<int>&prices,int i,int j,int num)
    {
        if(i==size(prices)||num==0)return 0;
        int max_profit=0;
        if(memo[i][j][num]!=-1)return memo[i][j][num];
        if(!j)
            max_profit=max(max_profit,dp(prices,i+1,!j,num)-prices[i]);
        else
            max_profit=max(max_profit,dp(prices,i+1,!j,num-1)+prices[i]);  
        
            max_profit=max(max_profit,dp(prices,i+1,j,num));     
        return memo[i][j][num]=max_profit;
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        int n=size(prices);
        memo.resize(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return dp(prices,0,false,k);
    }
};