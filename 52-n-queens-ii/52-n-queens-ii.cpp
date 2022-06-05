class Solution {
    vector<vector<int>>board;
public:
    Solution() :board(9,vector<int>(9,0))
    {
        
    }
    bool ispossible(int n,int row,int col)
    {
        for(int i=row-1;i>=0;i--)
        {
            if(board[i][col]==1)
                return false;
            
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]==1)
                return false;
        }    
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
        {
            if(board[i][j]==1)
                return false;
        }
        return true;
    }
    int totalNQueens(int n) {
        return helper(n,0);
    }
    int  helper(int n,int row)
    {
        if(row==n)
        {
            return 1;
        }
        int ans=0;
        for(int j=0;j<n;j++)
        {
            if(ispossible(n,row,j))
            {
                board[row][j]=1;
                ans+=helper(n,row+1);
                board[row][j]=0;
            }
        }
        return ans;
    }
};