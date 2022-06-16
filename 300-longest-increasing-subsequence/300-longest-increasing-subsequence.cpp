class Solution {
public:
    vector<vector<int>>memo;
    int dp(const vector<int> &A,int i,int j,vector<vector<int>>&memo)
    {
        if(j-1==size(A))
            return 0;

        if(memo[i][j]!=-1)
            return memo[i][j];

        if(i==0||A[j-1]>A[i-1])
        {
            memo[i][j]=1+dp(A,j,j+1,memo);
        }

        return memo[i][j]=max(memo[i][j],dp(A,i,j+1,memo));

    }
    int lengthOfLIS(vector<int>& A) 
    {
        int n=size(A);
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        return dp(A,0,1,memo);   
    }
};