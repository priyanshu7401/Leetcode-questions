class Solution {
public:
    int memo[100][100][100]={0};
    
    int dp(vector<int>&nums,int i,int j,int k)
    {
        if(i>j)
            return 0;
        if(memo[i][j][k]!=0)
            return memo[i][j][k];
        int res=(k+1)*(k+1)+dp(nums,i+1,j,0);
        for(int m=i+1;m<=j;m++)
        {
            if(nums[i]==nums[m])
            {
                res=max(res,dp(nums,i+1,m-1,0)+dp(nums,m,j,k+1));
            }
        }
        return memo[i][j][k]=res;
    }
    int removeBoxes(vector<int>& boxes) 
    {
    int n=size(boxes);
    return dp(boxes,0,n-1,0);    
    }
};