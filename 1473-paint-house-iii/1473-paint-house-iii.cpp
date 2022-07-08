class Solution {
public:    
    int memo[101][101][21]={};
    int dp(vector<int>&houses,vector<vector<int>>&cost,int m,int n,int i,int target,int nei=0,int last_clr=-1)
    {
        if(i==size(houses))
        {
            if(nei==target)
            {
                // cout<<nei<<endl;
                return 0;
            }
            return 1e7;
        }
        if(nei>target)return 1e7;
        if(memo[i][nei][last_clr]!=0)
            return memo[i][nei][last_clr];
        int ans=INT_MAX;
        if(houses[i]!=0)
        {
            int neigh=nei+(i==0||(houses[i])!=last_clr);
            ans=dp(houses,cost,m,n,i+1,target,neigh,houses[i]);
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                int neigh=nei+(i==0||(j+1)!=last_clr);
                ans=min(ans,cost[i][j]+dp(houses,cost,m,n,i+1,target,neigh,j+1));
            }            
        }
        return memo[i][nei][last_clr]=ans;
        // return ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        // memo.resize(m,vector<int>(target+1,-1));
        int ans=dp(houses,cost,m,n,0,target,0,0);
        return ((ans>=1e7)?-1:ans);
    }
};