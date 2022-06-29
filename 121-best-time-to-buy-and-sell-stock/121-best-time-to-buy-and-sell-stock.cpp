class Solution {
public:
    vector<vector<int>>memo;
    int dfs(vector<int>& prices,int i,int buy)
    {
        if(i==size(prices))
            return 0;
        if(memo[i][buy]!=-1)
            return memo[i][buy];
        if(buy)
        {
            return memo[i][buy]=max(dfs(prices,i+1,buy),dfs(prices,i+1,!buy)-prices[i]);
        }
        return memo[i][buy]=max(prices[i],dfs(prices,i+1,buy));
    }
    int maxProfit(vector<int>& prices) 
    {
        memo.resize(size(prices)+1,vector<int>(2,-1));
        return dfs(prices,0,1);    
    }
};