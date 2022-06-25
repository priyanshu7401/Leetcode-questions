class Solution {
public:
    pair<int,bool> dfs(vector<vector<int>>&adj,int root,vector<int>&visited,vector<bool>&hasApple)
    {
        if(visited[root])
            return {0,0};
        int ans=0,hasans=hasApple[root];
        visited[root]=1;
        for(int i=0;i<size(adj[root]);i++)
        {
            auto [time,has]=dfs(adj,adj[root][i],visited,hasApple);
            if(has)
                ans+=(time+2);
            hasans|=has;
        }
        return {ans,hasans};
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        for(int i=0;i<size(edges);i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj,0,visited,hasApple).first;
    }
};