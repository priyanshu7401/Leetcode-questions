class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
    int n=matrix.size();
    for(int i=0;i<=(n-1)/2;i++)   
    {
        for(int j=i;j<(n-i-1);j++)
        {
            int row[]={i,j,n-i-1,n-j-1};
            int col[]={j,n-i-1,n-j-1,i};
            int a=matrix[row[3]][col[3]],k=3;
            for(;k>0;k--)
            {
                matrix[row[k]][col[k]]=matrix[row[k-1]][col[k-1]];
            }
            matrix[row[0]][col[0]]=a;
        }
    }
    }
};