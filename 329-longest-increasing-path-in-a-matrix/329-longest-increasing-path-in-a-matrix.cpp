class Solution {
public:
    vector<vector<int>>visited;
    int dir[5]={-1,0,1,0,-1};
    int dp(vector<vector<int>>&matrix,int i,int j)
    {
        if(visited[i][j]!=-1)
            return visited[i][j];
        visited[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int I=i+dir[k];
            int J=j+dir[k+1];
            if(I<0||J<0||I==matrix.size()||J==matrix[0].size()||matrix[i][j]>=matrix[I][J])
                continue;
            visited[i][j]=max(visited[i][j],1+dp(matrix,I,J));
        }
        return visited[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
       visited.resize(m,vector<int>(n,-1));
       int ans=0;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(visited[i][j]==-1)
               {
                   ans=max(ans,dp(matrix,i,j));
               }
           }
       }
        return ans;
    }
};