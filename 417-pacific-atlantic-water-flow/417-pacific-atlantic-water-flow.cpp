int dir[]={-1,0,1,0,-1};
class Solution {
public:
    vector<vector<int>> ans,visited;
    void bfs(vector<vector<int>>&heights,queue<pair<int,int>>&q)
    {
        int m=heights.size(),n=heights[0].size();
        while(!q.empty())
        {
             auto [i,j]=q.front();
             q.pop();
             for(int k=0;k<4;k++)
             {
                 int I=i+dir[k];
                 int J=j+dir[k+1];
                 if(I>=0&&J>=0&&I<m&&J<n&&!visited[I][J]&&heights[I][J]>=heights[i][j])
                 {
                     visited[I][J]=1;
                     ans[I][J]++;
                     q.push({I,J});
                 }
             }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
    int m=heights.size(),n=heights[0].size();
    ans.resize(m,vector<int>(n,0));
    visited.resize(m,vector<int>(n,0));
    queue<pair<int,int>>q;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0||j==0)
            {
                visited[i][j]=1,q.push({i,j}),ans[i][j]++;
            }
        }
    }
    bfs(heights,q);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            visited[i][j]=0;
            if(i==m-1||j==n-1)
            {
                visited[i][j]=1,q.push({i,j}),ans[i][j]++;
            }
        }
    }    
    bfs(heights,q); 
    vector<vector<int>>res;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ans[i][j]==2)
            {
             res.push_back({i,j});   
            }
        }
    }
        return res;
    }
};