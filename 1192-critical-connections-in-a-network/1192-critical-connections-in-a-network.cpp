class Solution {
public:
   
    set<vector<int>>conn;
    vector<vector<int>>adj,ans;
    vector<int>rank;
    
    int dfs(int node,int depth)
    {
        if(rank[node]>=0)
            return rank[node];//if visited return;
        rank[node]=depth;
        int mindepth=INT_MAX;
        for(auto neighbour: adj[node])
        {
            if(rank[neighbour]==depth-1)
                continue; // dont travel its parent
            int backdepth=dfs(neighbour,depth+1);
            mindepth=min(mindepth,backdepth);
            if(backdepth<=depth)
            {
                    cout<<node<<" "<<neighbour<<endl;
                    conn.erase({min(node,neighbour),max(node,neighbour)});
            }
        }
        // rank[node]=INT_MAX;
        return mindepth;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        adj.resize(n);
        for(int i=0;i<size(connections);i++)
        {
            
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            conn.insert({min(connections[i][0],connections[i][1]),max(connections[i][0],connections[i][1])});
        }
        rank.resize(n,-2);
        
        int mindepth=dfs(0,0);
        
        for(auto connection : conn)
        {
            ans.push_back(connection);
        }
        return ans;
    }
};