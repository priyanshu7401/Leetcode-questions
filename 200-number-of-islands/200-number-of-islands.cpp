class Solution {
    int m;
    int n;
public:
    void helper(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0||i>=m||j<0||j>=n||grid[i][j]=='0')
        {
            return ;
        }
        grid[i][j]='0';
        helper(grid,i+1,j);
        helper(grid,i-1,j);
        helper(grid,i,j+1);
        helper(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans+=1;
                    helper(grid,i,j);
                }
            }
        }
        return ans;
        }
};