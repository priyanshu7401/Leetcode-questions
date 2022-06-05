class Solution {
public:
    int mod=1e9+7;
    vector<int> djackstra(vector<vector<vector<int>>>&graph,int n)
    {
        vector<int>dist(n+1,INT_MAX);
        dist[n]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({dist[n],n});
        while(!pq.empty())
        {
           auto temp=pq.top();
           pq.pop();
           for(int i=0;i<graph[temp[1]].size();i++)
           {
               if(graph[temp[1]][i][1]+temp[0]<dist[graph[temp[1]][i][0]])
               {
                   pq.push({graph[temp[1]][i][1]+temp[0],graph[temp[1]][i][0]});
                   dist[graph[temp[1]][i][0]]=graph[temp[1]][i][1]+temp[0];
               }      
           }
        }
        return dist;
    }
    vector<int>dp;
    int dfs(vector<vector<vector<int>>>&graphs,vector<int>&dist,int src,int end)
    {
        if(src==end)
            return 1;
        int res=0;
        if(dp[src]!=-1)
            return dp[src];
        for(auto vec:graphs[src])
        {
            if(dist[src]>dist[vec[0]])
            {
                res=1LL*(res+dfs(graphs,dist,vec[0],end))%mod;
            }
        }
        return dp[src]=res;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) 
    {
     dp.resize(n+1,-1);
     vector<vector<vector<int>>>graphs(n+1);
     for(int i=0;i<edges.size();i++)
     {
         graphs[edges[i][0]].push_back({edges[i][1],edges[i][2]});
         graphs[edges[i][1]].push_back({edges[i][0],edges[i][2]});
     }
     vector<int>dist=djackstra(graphs,n);
        
     return dfs(graphs,dist,1,n);
     }
};