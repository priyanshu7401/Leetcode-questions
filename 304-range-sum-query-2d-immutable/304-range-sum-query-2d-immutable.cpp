class NumMatrix {
    vector<vector<int>>num;
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        prefixsum(matrix);
    
        num=matrix;
        // showmatrix(this->matrix);
        
    }
//     void showmatrix()
//     {
//         int m=num.size();
//         int n=matrix[0].size();
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//                 cout<<matrix[i][j]<<" ";
//             cout<<endl;
//         }
    
//     }
    void prefixsum(vector<vector<int>>&matrix)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=1;i<m;i++)
        {
            matrix[i][0]+=matrix[i-1][0];
        }
        for(int j=1;j<n;j++)
        {
            matrix[0][j]+=matrix[0][j-1];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j]=(matrix[i][j]+matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1]);
            }
        }
        }
    int element(int x,int y)
    {
        if(x<0)
            return 0;
        else if(y<0)
            return 0;
        else
            return num[x][y];
    }
    int sumRegion(int row1, int col1, int row2, int col2) 
    {

     return element(row1-1,col1-1)+element(row2,col2)-element(row2,col1-1)-element(row1-1,col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */