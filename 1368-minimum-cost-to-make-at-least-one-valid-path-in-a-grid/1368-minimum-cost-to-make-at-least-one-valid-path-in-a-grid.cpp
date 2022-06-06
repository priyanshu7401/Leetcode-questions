 // 2 d  djackstra
#define tii tuple<int,int,int>
#define pii pair<int,int>
class Solution {
public:
    pii findir(int i,int j,int num)
    {
        
        if(num==1)
            return make_pair(i,j+1);
        if(num==2)
            return make_pair(i,j-1);
        if(num==3)
            return make_pair(i+1,j);
        else
            return make_pair(i-1,j);
    }
    int dir[5]={-1,0,1,0,-1};
    int minCost(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        priority_queue<tii, vector<tii>,greater<tii>>pq;
        pq.push({0,0,0});
        while(!pq.empty())
        {
            auto [cost,i,j]=pq.top();
            pq.pop();
            auto [I,J]=findir(i,j,grid[i][j]);
            for(int k=0;k<4;k++)
            {
                int I1=i+dir[k];
                int J1=j+dir[k+1];
                if(I1<0||I1==m||J1<0||J1==n)
                    continue;
                
                if(dist[I1][J1]>(!(I==I1&&J==J1))+cost)
                {
                    dist[I1][J1]=(!(I==I1&&J==J1))+cost;
                    pq.push({dist[I1][J1],I1,J1});
                }       
            }
        }
        return dist[m-1][n-1];
    }
};