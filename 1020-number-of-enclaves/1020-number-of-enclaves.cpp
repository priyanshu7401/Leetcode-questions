int dir []={1,0,-1,0,1};
class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j)
    {
        int m=size(grid),n=size(grid[0]);
        if(i<0||j<0||i==m||j==n||!grid[i][j])
            return;
        grid[i][j]=0;
        for(int k=0;k<4;k++)
        {
            int I=i+dir[k];
            int J=j+dir[k+1];
            dfs(grid,I,J);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0||i==m-1||j==n-1)
                    dfs(grid,i,j);
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
            
        }
        int ans=0;
        for(int i=0;i<m;i++)
            ans+=accumulate(begin(grid[i]),end(grid[i]),0);
        
        return ans;
    }
};