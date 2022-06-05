class Solution {
public:
    
    vector<vector<vector<int>>>adj(int n,vector<vector<int>>&flights)
    {
       vector<vector<vector<int>>>graphs(n+1);
       for(int i=0;i<flights.size();i++)
       {
          graphs[flights[i][0]].push_back({flights[i][2],flights[i][1]});
          // graphs[flights[i][1]].push_back({flights[i][2],flights[i][0]}); 
       }
        return graphs;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<vector<int>>>graphs=adj(n,flights);
        // cout<<graphs[0].size()<<endl;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;
        pq.push({0,0,src});//{dist,nth-stop,node};
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            if(temp[1]>k)
                continue;
            for(int i=0;i<graphs[temp[2]].size();i++)
            {
                if(dist[graphs[temp[2]][i][1]][temp[1]+1]>graphs[temp[2]][i][0]+temp[0])
                {
                 dist[graphs[temp[2]][i][1]][temp[1]+1]=graphs[temp[2]][i][0]+temp[0];
                 pq.push({dist[graphs[temp[2]][i][1]][temp[1]+1],temp[1]+1,graphs[temp[2]][i][1]});
                }
            }
        }
        int ans=INT_MAX;
         for(int i=0;i<dist[dst].size();i++)
             ans=min(ans,dist[dst][i]);
    return ans==INT_MAX?-1:ans;    
    }
};