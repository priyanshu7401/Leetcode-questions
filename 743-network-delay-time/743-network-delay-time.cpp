class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
     vector<vector<pair<int,int>>>adj(n+1);
     for(int i=0;i<size(times);i++)
     {
         adj[times[i][0]].push_back({times[i][2],times[i][1]});
     }
     vector<int>distance(n+1,INT_MAX);
     distance[k]=0;
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     pq.push({0,k});
     while(!pq.empty())
     {
         auto [time,node]=pq.top();
         pq.pop();
         if(time>distance[node])
         {
             continue;
         }
         for(auto [t,neighbor]:adj[node])
         {
             if(distance[neighbor]>time+t)
             {
                 distance[neighbor]=time+t;
                 pq.push({distance[neighbor],neighbor});
             }
         }
     }
        int ans=0;
        for(int i=1;i<n+1;i++)
        {
            ans=max(ans,distance[i]);
            // cout<<distance[i]<<endl;
        }
        return ans==INT_MAX?-1:ans;
    }
};