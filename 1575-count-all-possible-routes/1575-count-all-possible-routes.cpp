class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>dp;
    int dfs(vector<int>&locations,int cur,int finish,int fuel)
    {
         if(fuel<0)
            return 0;
        if(dp[cur][fuel]!=-1)
            return dp[cur][fuel];
        int res=(cur==finish);
        for(int i=0;i<size(locations);i++)
        {
            if(i!=cur)
            {
                res=1LL*(res+dfs(locations,i,finish,fuel-abs(locations[cur]-locations[i])))%mod;
            }
        }
        return dp[cur][fuel]=res;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        int n=locations.size();
        dp.resize(n+1,vector<int>(fuel+1,-1));
        return dfs(locations,start,finish,fuel);    
    }
};