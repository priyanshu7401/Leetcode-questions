#define pii pair<int,int>
class Solution {
public:
    vector<vector<pii>>dp;
    pii dfs(vector<int>&arr,int i,int j)
    {
        if(j==i)
        {
          return {0,arr[i]};    
        }
        if(dp[i][j].first!=-1)
            return dp[i][j];
        pii res=make_pair(INT_MAX,0);
        for(int k=i;k<j;k++)
        {
            auto [sum1,max1]=dfs(arr,i,k);
            auto [sum2,max2]=dfs(arr,k+1,j);
            if(sum1+sum2+max1*max2<res.first)
            {
                res.first=sum1+sum2+max1*max2;
                res.second=max(max1,max2);
            }
        }
        return dp[i][j]=res;
    }
    int mctFromLeafValues(vector<int>& arr) 
    {
        
        int n=size(arr);
        dp.resize(n,vector<pii>(n,{-1,-1}));
        pii ans=dfs(arr,0,n-1);    
        return ans.first;
    }
};