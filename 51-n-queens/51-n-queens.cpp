class Solution {
    vector<string>board;
    vector<vector<string>>output;
public:
    Solution() :board(9) 
    {
        for(int i=0;i<9;i++)
        {
            board[i]=".........";
        }
    }
    bool ispossible(int n,int row,int col)
    {
        for(int i=row-1;i>=0;i--)
        {
            if(board[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        helper(n,0);
        return output;
    }
    
    void helper(int n,int row)
    {
        if(row==n)
        {
            vector<string>ans;
            for(int i=0;i<n;i++)
            {
              ans.push_back(board[i].substr(0,n));
            }
            output.push_back(ans);
            return;
        }
        for(int j=0;j<n;j++)
        {
           if(ispossible(n,row,j))
           {
               board[row][j]='Q';
               helper(n,row+1);
               board[row][j]='.';
           }
               
        }
          return ;  
    }
};