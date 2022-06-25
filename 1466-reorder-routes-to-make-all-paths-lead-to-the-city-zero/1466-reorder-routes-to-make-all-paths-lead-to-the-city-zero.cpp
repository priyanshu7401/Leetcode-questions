class Solution {
public:
    int dfs(int n,vector<vector<pair<int,bool>>>&adj,int start,vector<int>&visited)
    {
        if(visited[start])
            return 0;
        visited[start]=1;
        int ans=0;
        for(int i=0;i<adj[start].size();i++)
        {
            if(!visited[adj[start][i].first])
                ans+=dfs(n,adj,adj[start][i].first,visited)+adj[start][i].second;
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<pair<int,bool>>>adj(n);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
        }
        vector<int>visited(n,0);
        return dfs(n,adj,0,visited);
    }
};