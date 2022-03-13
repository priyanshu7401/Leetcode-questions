class Solution 
{
public:
    int calculate(vector<vector<int>>&mat)
    {
        int m=size(mat);
        int n=size(mat[0]);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=mat[i][j]<<(m*i+j);
            }
        }
        return ans;
    }
    
    void flip(vector<vector<int>>&mat ,int i,int j)
    {
        int m=size(mat);
        int n=size(mat[0]);        
        mat[i][j]=!mat[i][j];
        if(i>0)
            mat[i-1][j]=!mat[i-1][j];     
        if(i<m-1)
            mat[i+1][j]=!mat[i+1][j];
        if(j>0)
            mat[i][j-1]=!mat[i][j-1];
        if(j<n-1)
            mat[i][j+1]=!mat[i][j+1];        
    }
    
    int minFlips(vector<vector<int>>& mat) 
    {
        int m=size(mat);
        int n=size(mat[0]);
        queue<vector<vector<int>>>q;
        q.push(mat);
        int ans=0;
        vector<int>visited(1<<10,0);
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                mat=q.front();
                q.pop();
                
                if(calculate(mat)==0)
                    return ans;
                
                for(int j=0;j<m;j++)
                {
                    for(int k=0;k<n;k++)
                    {
                        flip(mat,j,k);
                        int bitmask=calculate(mat);
                        if(!visited[bitmask])
                        {
                            visited[bitmask]=1;
                            q.push(mat);
                        }
                        flip(mat,j,k);
                    }
                }
            }
            ans++;
        }
    return -1;
    }
};