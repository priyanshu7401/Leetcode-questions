class Solution {
public:
    vector<int>djackstra(int n,vector<vector<int>>&edges,int src)
    {
        vector<vector<vector<int>>>graphs(n);
        for(int i=0;i<size(edges);i++)
        {
            graphs[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            graphs[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            for(int i=0;i<size(graphs[temp[1]]);i++)
            {
                if(dist[graphs[temp[1]][i][1]]>graphs[temp[1]][i][0]+dist[temp[1]])
                {
                   dist[graphs[temp[1]][i][1]]=graphs[temp[1]][i][0]+dist[temp[1]];
                   pq.push({dist[graphs[temp[1]][i][1]],graphs[temp[1]][i][1]});
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int th) 
    {
    int ans=-1,count=INT_MAX;
    for(int src=n-1;src>=0;src--)
    {
        vector<int>dst=djackstra(n,edges,src);   
        int cnt=0;
        for(int i=0;i<size(dst);i++)
        {
            cnt+=(dst[i]<=th);
        }
        if(cnt<count)
        {
            count=cnt;
            ans=src;
        }
    }
        return ans;
    }
};