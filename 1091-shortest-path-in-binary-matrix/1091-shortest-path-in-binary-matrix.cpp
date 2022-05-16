class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
    int m=size(grid),n=size(grid[0]);
    if(grid[0][0]+grid[m-1][n-1])
        return -1;
    int ans=1;
    queue<pair<int,int>>q;
    q.push({0,0});
    while(!q.empty())
    {
        int N=size(q);
        for(int i=0;i<N;i++)
        {
            auto [x,y]=q.front();
            q.pop();
            if(x==m-1&&y==n-1)
                return ans;
            if(x-1>=0&&y-1>=0&&!grid[x-1][y-1])
            {
                q.push({x-1,y-1});
                grid[x-1][y-1]=1;
            }
            if(x-1>=0&&y>=0&&!grid[x-1][y])
            {
                q.push({x-1,y});
                grid[x-1][y]=1;
            }
            if(x-1>=0&&y+1<n&&!grid[x-1][y+1])
            {
                q.push({x-1,y+1});
                grid[x-1][y+1]=1;
            }
            if(y-1>=0&&!grid[x][y-1])
            {
                q.push({x,y-1});
                grid[x][y-1]=1;
            }  
            if(y+1<n&&!grid[x][y+1])
            {
                q.push({x,y+1});
                grid[x][y+1]=1;
            }
            if(x+1<m&&y-1>=0&&!grid[x+1][y-1])
            {
                q.push({x+1,y-1});
                grid[x+1][y-1]=1;
            }
            if(x+1<m&&y>=0&&!grid[x+1][y])
            {
                q.push({x+1,y});
                grid[x+1][y]=1;
            }
            if(x+1<m&&y+1<n&&!grid[x+1][y+1])
            {
                q.push({x+1,y+1});
                grid[x+1][y+1]=1;
            }    
        }
        ans++;
    }
    return -1;
    }
};