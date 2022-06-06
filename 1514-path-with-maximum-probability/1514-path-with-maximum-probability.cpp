class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
     vector<vector<pair<double,int>>>adj(n);
     for(int i=0;i<size(edges);i++)
     {
         adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
         adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
     }
        
     vector<double>distance(n+1,0);
     distance[start]=(double)1;
     priority_queue<pair<double,int>,vector<pair<double,int>>>pq;
     pq.push({1.000,start});
     while(!pq.empty())
     {
         auto [prob,node]=pq.top();
        
         pq.pop();
         // if(time<=distance[node])
         // {
         //     continue;
         // }
         for(auto [t,neighbor]:adj[node])
         {
              // cout<<prob<<" "<<node<<" "<<t<<endl;
             if(distance[neighbor]<prob*t)
             {
                 distance[neighbor]=prob*t;
                 pq.push({distance[neighbor],neighbor});
             }
         }
     }
        return distance[end];    
    }
};