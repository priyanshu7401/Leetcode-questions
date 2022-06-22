class Solution {
public:
    int dfs(vector<vector<int>>&adj,int start,vector<int>& informTime)
    {
        int ans=0;
        for(int i=0;i<size(adj[start]);i++)
        {
            ans=max(ans,informTime[start]+dfs(adj,adj[start][i],informTime));
        }
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
     vector<vector<int>>adj(n); 
     for(int i=0;i<n;i++)
     {
         if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
     }
     return dfs(adj,headID,informTime); 
    }
};