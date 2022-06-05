class Solution {
public:
    int dir[5]={-1,0,1,0,-1};
    int djackstra(vector<vector<int>>&grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[i][j],i,j});
        dist[i][j]=grid[i][j];
        
        while(!pq.empty())
        {
            vector<int>temp=pq.top();
            pq.pop();
            for(int k=0;k<4;k++)
            {
                int I=temp[1]+dir[k];
                int J=temp[2]+dir[k+1];
                if(I<0||I==m||J<0||J>=n||grid[I][J]+temp[0]>=dist[I][J])
                    continue;
                dist[I][J]=grid[I][J]+temp[0];
                pq.push({dist[I][J],I,J});
            }
        }
        return dist[m-1][n-1];
    }
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        return djackstra(grid,0,0);    
    }
};